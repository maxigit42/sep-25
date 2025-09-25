/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:37:57 by mwilline          #+#    #+#             */
/*   Updated: 2024/09/30 18:50:38 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

// int	main(void)
// {
// 	int *array = (int *)ft_calloc(5, sizeof(int));

// 	if (array == NULL)
// 	{
// 		return (1);
// 	}

// 	int i;
// 	i = 0;
// 	while (i < 5)
// 	{
// 		array[i] = i + 1;
// 		i++;
// 	}

// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d", array[i]);
// 		i++;
// 	}

// 	free(array);

// 	return (0);
// }