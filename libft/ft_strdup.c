/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:23:32 by mwilline          #+#    #+#             */
/*   Updated: 2024/09/30 18:52:22 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	size_t	i;

	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// int	main(void)
// {
// 	const char origin[] = "maximo";
// 	char *copia = ft_strdup(origin);

// 	if (copia == NULL)
// 	{
// 		return (1);
// 	}

// 	printf("%s\n", origin);
// 	printf("%s\n", copia);

// 	free(copia);

// 	return (0);
// }