/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:12:44 by mwilline          #+#    #+#             */
/*   Updated: 2024/10/02 13:29:14 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	count_dig(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count = 1;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	ft_ab(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = count_dig(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		len--;
		str[len] = '0' + ft_ab(n % 10);
		n /= 10;
	}
	return (str);
}

//  int	main(void)
//  {
//  	int i = -1;
// 	char *s = ft_itao(i);
//  	printf("%s", s);
//  	free(s);
//  	return (0);
//  }