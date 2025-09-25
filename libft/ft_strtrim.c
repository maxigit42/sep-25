/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:30:33 by mwilline          #+#    #+#             */
/*   Updated: 2024/09/30 18:53:04 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	total_size;
	char	*copy;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	total_size = end - start;
	copy = (char *)malloc(total_size + 1);
	if (!copy)
	{
		return (NULL);
	}
	ft_strlcpy(copy, s1 + start, total_size + 1);
	copy[total_size] = '\0';
	return (copy);
}

// int	main(void)
// {
// 	char s1[10] = "mluciom";
// 	const char set[] = "m";
// 	char *copy = ft_strtrim(s1, set);
// 	printf("%s", copy);
// 	free(copy);
// 	return (0);
// }