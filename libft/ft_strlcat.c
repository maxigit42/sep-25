/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:01:17 by mwilline          #+#    #+#             */
/*   Updated: 2024/09/30 18:52:36 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	destl;
	size_t	strl;

	d = 0;
	s = 0;
	while (dst[d] != '\0' && d < size)
	{
		d++;
	}
	destl = d;
	strl = ft_strlen(src);
	if (size <= destl)
	{
		return (size + strl);
	}
	s = 0;
	while (src[s] != '\0' && (destl + s) < (size - 1))
	{
		dst[destl + s] = src[s];
		s++;
	}
	dst[destl + s] = '\0';
	return (destl + strl);
}

// int	main(void)
// {
// 	char	str[6] = "cio";
// 	char	dest[3] = "lu";
// 	size_t	s;

// 	s = ft_strlcat(dest, str, 4);
// 	printf("%zu\n", s);
// 	printf("%s", dest);
// 	return (0);
// }
