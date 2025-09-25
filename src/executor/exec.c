/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 03:30:59 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/29 03:30:59 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     find_valid_path(char **paths, char **envp, char **cmd)
{
    char    *temp;
    char    *full_path;
    int i;

    if (!cmd || !cmd[0])
        return 0;
    i = 0;
    while(paths[i])
    {
        temp = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(temp, cmd[0]);
        free(temp);
        if(!full_path)
            return(0);
        if(access(full_path, X_OK) == 0)
        {
            execve(full_path, cmd, envp);
            perror("execve");
            free(full_path);
            return (0);
        }
        free(full_path);
        i++;
    }
    return(0);
}

void   execute_cmd(t_env *env, char **cmd)
{
    char    *full_envp;
    char    **paths;
    char    **envp_array;

    if (!env)
    {
        printf("⛔ envp es NULL\n");
        return;
    }
    full_envp = get_env_value_list(env, "PATH");
    if (!full_envp)
    {
        printf("⛔ No se encontró PATH en envp\n");
        return;
    }
    paths = ft_split(full_envp, ':');
    if(!paths)
        return ;
    envp_array = env_list_to_array(env);
    if(!envp_array)
    {
        free_split(paths);
        return;
    }
    if(!find_valid_path(paths, envp_array, cmd))
        printf("command not found\n");
    free_split(paths);
    free_split(envp_array);
}

char **get_cmds(t_data *data)
{
    char **args;
    t_token *current;
    int i;

    i = 0;
    current = data->token;
    while (current && current->type == CMD)
    {
        i++;    
        current = current->next;
    }
    args = malloc(sizeof(char *) * (i + 1));
    if (!args)
        return NULL;
    i = 0;
    current = data->token;
    while (current && current->type == CMD)
    {
        args[i++] = ft_strdup(current->str);
        current = current->next;
    }
    args[i] = NULL;
    return(args);
}