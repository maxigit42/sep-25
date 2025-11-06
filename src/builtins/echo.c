/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:51:03 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/05 20:12:55 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	print_str(t_data *data, char *str, int fd)
{
	int	i;
	char *new_key;
	char *text;

	i = 0;
	while(str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
			{
				ft_putnbr_fd(data->exit_status, 1);
				i++;
			}
			else
			{	
				new_key = ft_strdup(&str[i + 1]);
				text = ft_strdup(get_env_value_list(data->env, new_key));
				if (!text)
				{
					free(new_key);
					return ;
				}
				ft_putstr_fd(text, fd);
				free(text);
				free(new_key);
				return ;
			}
		}
		else
			ft_putchar_fd(str[i], fd);
		i++;
	}
}

int builtin_echo(char **args, t_data *data)
{
	int i;
	int newline;
	
	i = 1;
	newline = 1;
	if(args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	while(args[i])
	{
		print_str(data, args[i], 1);
		if(args[i + 1])
			ft_putstr_fd(" ", 1);  // creo que no estoy pasando un caracter de espacio y estoy pasando una cadena
		i++;
	}
	if(newline)
		ft_putstr_fd("\n", 1);
	return(0);
}