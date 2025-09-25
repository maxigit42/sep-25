/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:22:41 by mwilline          #+#    #+#             */
/*   Updated: 2024/10/02 13:11:54 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	strl;
	size_t	i;

	strl = 0;
	i = 0;
	while (src[strl] != '\0')
	{
		strl++;
	}
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (strl);
}

// int	main(void)
// {
// 	char str[10] = "maximo";
// 	char dest[10];
// 	size_t s;
// 	s = ft_strlcpy(dest, str, 6);
// 	printf("%s\n", dest);
// 	printf("%zu", s);
// 	return (0);
// }