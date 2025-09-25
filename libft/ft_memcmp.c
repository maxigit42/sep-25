/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:06:03 by mwilline          #+#    #+#             */
/*   Updated: 2024/09/30 18:51:40 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1 = (const unsigned char *)s1;
	const unsigned char	*ptr2 = (const unsigned char *)s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (ptr1[i] < ptr2[i])
		{
			return (-1);
		}
		else if (ptr1[i] > ptr2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char s1[10] = "bb";
// 	char s2[10] = "bbb";
// 	int result;
// 	result = ft_memcmp(s1, s2, 10);
// 	printf("%i", result);
// 	return (0);
// }