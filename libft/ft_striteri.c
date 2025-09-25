/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:17:50 by mwilline          #+#    #+#             */
/*   Updated: 2024/10/02 13:37:47 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

void	fun(unsigned int i, char *c)
{
	*c += i;
}

// int	main(void)
// {
// 	char s[10] = "maxi";
// 	ft_striteri(s, fun);
// 	printf("Resultado: %s\n", s);
// 	return (0);
// }