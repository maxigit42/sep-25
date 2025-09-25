/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:39:32 by mwilline          #+#    #+#             */
/*   Updated: 2024/10/02 13:35:52 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*copy;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	copy = (char *)malloc(i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = f(i, s[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	funtion(unsigned int i, char c)
{
	return (c + i);
}

// int	main(void)
// {
// 	char *s = "maxi";
// 	char *result = ft_strmapi(s, funtion);
// 	printf("Resultado: %s\n", result);
// 	free(result);
// 	return (0);
// }