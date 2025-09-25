/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:02:28 by mwilline          #+#    #+#             */
/*   Updated: 2024/09/30 18:50:29 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	check_sign(const char *str, int *s)
{
	int	i;
	int	sign_count;

	i = 0;
	sign_count = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*s = -1;
		sign_count++;
		if (sign_count > 1)
			return (0);
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	s;

	i = skip_whitespace(str);
	num = 0;
	s = 1;
	i += check_sign(&str[i], &s);
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * s);
}
