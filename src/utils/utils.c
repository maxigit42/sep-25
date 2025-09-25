/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:46:19 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/22 18:32:43 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_error(char *str, int quit)
{
	printf("%s\n", str);
	exit(quit);
}

void	free_and_exit(char *str, char **envp, int exit)
{
	int i;

	i = 0;
	while(envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
	ft_error(str, exit);
}

void	free_split(char **str)
{
	int i;

	if(!str)
		return;
	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_list(t_token *head)
{
	t_token	*temp;

	while(head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}

void	ft_free(char *str, char **envp)
{
	int i;

	i = 0;
	while(envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
	printf("%s\n", str);
}

int count_pipe_args(t_token *token)
{
	t_token *current;
	int i;

	i = 0;
	current = token;
	while (current && current->type != PIPE)
	{
		if (current->type == OUTFILE || current->type == INFILE
			|| current->type == APPEND || current->type == HEREDOC)
		{
			current = current->next;
			if (current)
				current = current->next;
		}
		else
		{
			i++;
			current = current->next;
		}
	}
	return(i);
}

void free_args(t_data *data)
{
    int i = 0;

    if (data->cmd)
    {
        while (data->cmd[i])
            free_split(data->cmd[i++]);
        free(data->cmd);
        data->cmd = NULL;
    }

    if (data->pid)
    {
        free(data->pid);
        data->pid = NULL;
    }
}

int count_commands(t_token *token)
{
	t_token *current = token;
	int count = 1;  // empieza en 1 porque sin pipes hay al menos un comando

	while (current)
	{
		if (current->type == PIPE)
			count++;
		current = current->next;
	}
	return count;
}

void free_env_list(t_env *env)
{
    t_env *tmp;

    while (env)
    {
        tmp = env->next;
        free(env->key);
        free(env->value);
        free(env);
        env = tmp;
    }
}