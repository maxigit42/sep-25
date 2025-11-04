/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 23:47:45 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/04 02:00:49 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     **create_pipes(int  n_pipes)
{
    int **pipes;
    int i;

    i = 0;
    pipes = malloc(sizeof(int *) * n_pipes);
    while(i < n_pipes)
    {
        pipes[i] = malloc(sizeof(int) * 2);
        if (pipe(pipes[i]) == -1)
            ft_error("Pipe failed\n", 1);
        i++;
    }
    return(pipes);
}

void setup_child_pipes(int **pipes, int n_pipes, int index)
{
    int i;
    
    i = 0;
    while (i < n_pipes)
    {
        if (i != index - 1)
            close(pipes[i][0]);
        if (i != index)
            close(pipes[i][1]);
        i++;
    }
    // Si no es el primer comando, conecta su entrada al anterior
    if (index > 0)
        dup2(pipes[index - 1][0], STDIN_FILENO);
    // Si no es el último comando, conecta su salida al siguiente
    if (index < n_pipes)
        dup2(pipes[index][1], STDOUT_FILENO);
}

void close_all_pipes(int **pipes, int n_pipes)
{
    for (int i = 0; i < n_pipes; i++)
    {
        close(pipes[i][0]);     //quitar el for
        close(pipes[i][1]);
    }
}

void free_pipes(int **pipes, int n_pipes)
{
    for (int i = 0; i < n_pipes; i++)  //quitar el for
        free(pipes[i]);
    free(pipes);
}
