/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:59:26 by biniesta          #+#    #+#             */
/*   Updated: 2025/11/17 21:44:47 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_tokens(char *str)
{
	int		count;
	int		in_token;
	char	in_quote;
	int		i;

	count = 0;
	in_token = 0;
	in_quote = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && !in_quote)
			in_quote = str[i];
		else if (str[i] == in_quote)
			in_quote = 0;
		if ((str[i] == ' ' || str[i] == '\t') && !in_quote)
			in_token = 0;
		else if (!in_token)
		{
			in_token = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*extract_token(char *str, int len)
{
	char	*token;
	int		i;
	int		j;
	char	quote;

	token = malloc(len + 1);
	if (!token)
		return (NULL);
	i = 0;
	j = 0;
	quote = 0;
	while (i < len)
	{
		if ((str[i] == '\'' || str[i] == '"') && !quote)
			quote = str[i++];
		else if (str[i] == quote)
		{
			quote = 0;
			i++;
		}
		else
			token[j++] = str[i++];
	}
	token[j] = '\0';
	return (token);
}

static int	skip_spaces(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

static void	fill_token(t_parse_token *tok, char *str, int len)
{
	tok->in_single_quote = (str[0] == '\'');
	tok->in_double_quote = (str[0] == '"');
	tok->str = extract_token(str, len);
}

int	parse_quote_tokens(char *str, t_parse_token *tokens)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (str[i])
	{
		i = skip_spaces(str, i);
		if (!str[i])
			break ;
		len = token_len(&str[i]);
		fill_token(&tokens[j], &str[i], len);
		i += len;
		j++;
	}
	tokens[j].str = NULL;
	return (1);
}
