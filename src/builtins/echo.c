/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:51:03 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/13 00:00:15 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int builtin_echo(char **args, t_data *data)
{
    int i = 1;
    int newline = 1;

    // Soporte para múltiples -n
    while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
    {
        int j = 1;
        while (args[i][j] == 'n')
            j++;
        if (args[i][j] != '\0')
            break;
        newline = 0;
        i++;
    }

    // Ya no expandas aquí, los args ya vienen procesados
    while (args[i])
    {
        ft_putstr_fd(args[i], STDOUT_FILENO);
        if (args[i + 1])
            ft_putchar_fd(' ', STDOUT_FILENO);
        i++;
    }

    if (newline)
        ft_putchar_fd('\n', STDOUT_FILENO);
    data->exit_status = 0;
    return (0);
}