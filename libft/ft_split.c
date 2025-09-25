/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:58:14 by mwilline          #+#    #+#             */
/*   Updated: 2024/10/02 17:22:06 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	*ft_free(char **ptr, int i)
{
	while (i > 0)
		free(ptr[--i]);
	free(ptr);
	return (NULL);
}

static char	*copy_word(char const *start, char const *end)
{
	char	*word;
	int		len;

	len = end - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static char	**split_str(char const *s, char c, int nwords)
{
	char		**result;
	int			i;
	const char	*start;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!result)
		return (NULL);
	while (i < nwords)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		result[i] = copy_word(start, s);
		if (!result[i])
			return (ft_free(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int	nwords;

	if (!s)
		return (NULL);
	nwords = count_words(s, c);
	return (split_str(s, c, nwords));
}

// int	main(void)
// {
// 	char str[] = "El camino,del,pescador";
// 	char delim = ',';
// 	char **result = ft_split(str, delim);

// 	for (int i = 0; result[i] != NULL; i++)
// 	{
// 		printf("Subcadena %d: %s\n", i, result[i]);
// 		free(result[i]);
// 	}
// 	free(result);

// 	return (0);
// }