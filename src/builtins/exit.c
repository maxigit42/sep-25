/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runo <runo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:58:11 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/14 11:06:12 by runo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_exit(char **args)
{
    int status = 0;

    printf("exit\n");
    if (args[1])
    {
        if (!ft_isdigit_str(args[1]))
        {
            ft_putstr_fd("minishell: exit: ", 2);
            ft_putstr_fd(args[1], 2);
            ft_putstr_fd(": numeric argument required\n", 2);   
        }
        status = ft_atoi(args[1]);
        if (args[2]) // demasiados argumentos
        {
            fprintf(stderr, "minishell: exit: too many arguments\n");
            return (1);
        }
    }
    exit(status);
}

int ft_isdigit_str(char *str)
{
    int i = 0;

    if (!str || !*str)
        return (0);

    // permitir signo opcional al inicio
    if (str[i] == '+' || str[i] == '-')
        i++;

    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

// no tengo permitido usar fprintf!!!!!!!!!!!!!!!!!!!