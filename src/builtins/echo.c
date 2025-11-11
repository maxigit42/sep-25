/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:51:03 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/11 04:31:29 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	print_str(t_data *data, const char *str, int fd)
{
	int		i;
	char	*var_name;
	char	*value;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			// Casos especiales de expansión
			if (str[i + 1] == '?')
			{
				ft_putnbr_fd(data->exit_status, fd);
				i += 2;
				continue;
			}
			// Variables normales: $VAR
			else if (ft_isalpha(str[i + 1]) || str[i + 1] == '_')
			{
				int len = 0;
				while (str[i + 1 + len] && (ft_isalnum(str[i + 1 + len]) || str[i + 1 + len] == '_'))
					len++;
				var_name = ft_substr(&str[i + 1], 0, len);
				value = get_env_value_list(data->env, var_name);
				if (value)
					ft_putstr_fd(value, fd);
				free(var_name);
				i += len + 1;
				continue;
			}
			// $ sin variable → se imprime tal cual
			else
				ft_putchar_fd('$', fd);
		}
		else
			ft_putchar_fd(str[i], fd);
		i++;
	}
}

/*
** builtin_echo — implementación segura y correcta
**
** - Soporta varios -n seguidos
** - Expande $VAR y $?
** - Maneja espacios correctamente
*/
int	builtin_echo(char **args, t_data *data)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;

	// Detectar múltiples flags -n consecutivos
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		int j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break; // no es solo "-n" o "-nnn"
		newline = 0;
		i++;
	}

	while (args[i])
	{
		print_str(data, args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}

	if (newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
	data->exit_status = 0;
	return (0);
}