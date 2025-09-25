/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:08:24 by mwilline          #+#    #+#             */
/*   Updated: 2024/09/30 17:25:24 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	char c[15] = "lucioperca";
// 	int num = 112;
// 	char *result = ft_strchr(c, num);

// 	if (result != NULL)
// 	{
// 		printf("%s\n", result);
// 	}
// 	else
// 	{
// 		printf("\n");
// 	}

// 	return (0);
// }