/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:58:11 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/18 19:52:15 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(char **args)
{
	printf("exit\n");
	if (args[1])
	{
		g_exit_status = ft_atoi(args[1]);
		if (!ft_isdigit_str(args[1]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(args[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			g_exit_status = 2;
		}
		if (args[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
	}
	exit(g_exit_status);
}

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
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
