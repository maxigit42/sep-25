/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:05:01 by mwilline          #+#    #+#             */
/*   Updated: 2024/09/30 18:52:59 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (0 <= i)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s[10] = "lucioperca";
// 	const char *s_cpy = (const char *)s;
// 	int c = 112;
// 	char *result;
// 	result = ft_strrchr(s_cpy, c);
// 	printf("%s\n", result);
// 	return (0);
// }