/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:20:22 by mwilline          #+#    #+#             */
/*   Updated: 2024/09/30 18:51:35 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)s;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)&ptr[i]);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	s[10] = "teckno";
// 	int		c;
// 	char	*result;

// 	c = 'k';
// 	result = ft_memchr(s, c, 10);
// 	printf("%s\n", result);
// 	return (0);
// }
