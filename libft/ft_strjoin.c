/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:00:52 by mwilline          #+#    #+#             */
/*   Updated: 2024/10/02 13:34:48 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*copy;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	j = -1;
	copy = (char *)malloc(len1 + len2 + 1);
	if (!copy)
		return (NULL);
	while (++i < len1)
		copy[i] = s1[i];
	while (++j < len2)
		copy[i + j] = s2[j];
	copy[i + j] = '\0';
	return (copy);
}

// int	main(void)
// {
// 	char s1[10] = "Maximo";
// 	char s2[10] = " Williner";
// 	char *con = ft_strjoin(s1, s2);
// 	printf("%s", con);
// 	free(con);
// 	return (0);
// }