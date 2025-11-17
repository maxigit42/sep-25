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

void	ft_error(char *str, int quit)
{
	printf("%s\n", str);
	exit(quit);
}

int	ft_strcmp(const char *s, const char *ss)
{
	int	i;

	i = 0;
	while (s[i] || ss[i])
	{
		if (s[i] != ss[i])
			return ((unsigned char)s[i] - (unsigned char)ss[i]);
		i++;
	}
	return (0);
}

int	has_redirection(t_token *token)
{
	while (token)
	{
		if (token->type == OUTFILE || token->type == INFILE
			|| token->type == APPEND || token->type == HEREDOC)
			return (1);
		token = token->next;
	}
	return (0);
}
