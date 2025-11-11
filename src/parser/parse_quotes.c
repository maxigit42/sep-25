
#include "minishell.h"

int	check_quotes(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && !quote)
			quote = str[i];
		else if (str[i] == quote)
			quote = 0;
		i++;
	}
	if (quote)
	{
		ft_putstr_fd("minishell: syntax error: unclosed quotes\n", 2);
		return (0);
	}
	return (1);
}

static int	count_tokens(char *str)
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

static int	token_len(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && !quote)
		{
			quote = str[i];
			i++;
		}
		else if (str[i] == quote)
		{
			quote = 0;
			i++;
		}
		else if ((str[i] == ' ' || str[i] == '\t') && !quote)
			break;
		else
			i++;
	}
	return (i);
}

static char	*extract_token(char *str, int len, int *single_flag, int *double_flag)
{
	char	*token;
	int		i = 0, j = 0;
	char	quote = 0;

	token = malloc(len + 1);
	if (!token)
		return (NULL);

	*single_flag = 0;
	*double_flag = 0;

	while (i < len)
	{
		if ((str[i] == '\'' || str[i] == '"') && !quote)
		{
			quote = str[i];
			if (quote == '\'') *single_flag = 1;
			if (quote == '"') *double_flag = 1;
			i++;
			continue;
		}
		if (str[i] == quote)
		{
			quote = 0;
			i++;
			continue;
		}
		token[j++] = str[i++];
	}
	token[j] = '\0';
	return (token);
}

char	**split_with_quotes(char *str)
{
	char	**tokens;
	int		count;
	int		i;
	int		j;
	int		len;

	if (!check_quotes(str))
		return (NULL);
	count = count_tokens(str);
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
		{
			len = token_len(&str[i]);
			tokens[j] = extract_token(&str[i], len, &single_flag, &double_flag);
			if (!tokens[j])
			{
				while (--j >= 0)
					free(tokens[j]);
				free(tokens);
				return (NULL);
			}
			j++;
			i += len;
		}
	}
	tokens[j] = NULL;
	return (tokens);
}
