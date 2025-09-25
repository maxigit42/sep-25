/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:15:44 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/21 17:26:50 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token     *ft_token_new(char *str)
{
    t_token  *new;
    
    new = malloc(sizeof(t_token));
    if(!new)
        ft_error(MALLOC_ERR, 0);
    new->str = ft_strdup(str);
    new->type = 0;
    new->infile = 0;
    new->outfile = 0;
    new->heredoc = 0;
    new->append = 0;
    new->next = NULL;
    return(new);
}

void    get_token_type(char *arg, t_token *token, t_data *data)
{
    if(ft_strncmp(arg, ">>", 2) == 0)
    {
        token->append++;
        token->type = APPEND;
    }
    else if(ft_strncmp(arg, "<<", 2) == 0)
    {
        token->heredoc++;
        token->type = HEREDOC;
    }
    else if(ft_strncmp(arg, ">", 1) == 0)
    {
        token->outfile++;
        token->type = OUTFILE;
    }
    else if(ft_strncmp(arg, "<", 1) == 0)
    {
        token->infile++;
        token->type = INFILE;
    }
    else if(ft_strncmp(arg, "|", 1) == 0)
    {
        data->pipe++;
        token->type = PIPE;
    }
    else if(is_builtin(arg))
        token->type = BUILTIN;
    else
        token->type = CMD;
}


void    put_lstback(t_token **head, t_token *new)
{
    t_token *temp;

    if(!head || !new)
        return;
    if(!*head)
    {
        *head = new;
        return;
    }
    temp = *head;
    while(temp->next)
        temp = temp->next;
    temp->next = new;
}

void    split_arg(char *args, t_data *data)
{
    char **token_array;
    int i;
    t_token *new;

    i = 0;
    token_array = ft_split(args, ' ');
    if (!token_array)
        return ;
    while(token_array[i])
    {
        new = ft_token_new(token_array[i]);
        put_lstback(&(data->token), new);
        get_token_type(token_array[i], new, data);
        i++;
    }
    free_split(token_array);
}

int is_builtin(const char *str)
{
    if(!str)
        return(0);
    return(
        ft_strncmp(str, "echo", 4) == 0 ||
        ft_strncmp(str, "cd", 2) == 0 ||
        ft_strncmp(str, "pwd", 3) == 0 ||
        ft_strncmp(str, "export", 6) == 0 ||
        ft_strncmp(str, "unset", 5) == 0 ||
        ft_strncmp(str, "env", 3) == 0 ||
        ft_strncmp(str, "exit", 4) == 0
    );
}