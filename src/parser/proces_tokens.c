/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 05:31:04 by biniesta          #+#    #+#             */
/*   Updated: 2025/11/17 21:45:20 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	countt_tokens(t_parse_token *tokens)
{
	int	count;

	count = 0;
	while (tokens[count].str)
		count++;
	return (count);
}

void	free_processed(char **processed, int up_to)
{
	while (--up_to >= 0)
		free(processed[up_to]);
	free(processed);
}

char	*process_single_token(t_parse_token token, t_data *data)
{
	if (token.in_single_quote == 1)
		return (ft_strdup(token.str));
	else
		return (expand_variables(token.str, data));
}

char	**process_tokens(t_parse_token *tokens, t_data *data)
{
	int		i;
	int		count;
	char	**processed;

	count = countt_tokens(tokens);
	processed = malloc(sizeof(char *) * (count + 1));
	if (!processed)
		return (NULL);
	i = 0;
	while (i < count)
	{
		processed[i] = process_single_token(tokens[i], data);
		if (!processed[i])
		{
			free_processed(processed, i);
			return (NULL);
		}
		i++;
	}
	processed[i] = NULL;
	return (processed);
}

t_parse_token	*split_with_quotes(char *str)
{
	t_parse_token	*tokens;
	int				count;

	if (!str)
		return (NULL);
	count = count_tokens(str);
	tokens = malloc(sizeof(t_parse_token) * (count + 1));
	if (!tokens)
		return (NULL);
	if (!parse_quote_tokens(str, tokens))
		return (NULL);
	return (tokens);
}
