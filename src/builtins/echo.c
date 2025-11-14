/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runo <runo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:51:03 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/14 11:03:13 by runo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	print_args(char **args, int i)
{
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
}

int	builtin_echo(char **args, t_data *data)
{
	int	i;
	int	newline;
	int	j;

	i = 1;
	newline = 1;
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break ;
		newline = 0;
		i++;
	}
	print_args(args, i);
	if (newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
	data->exit_status = 0;
	return (0);
}
