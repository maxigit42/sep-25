/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runo <runo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:17 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/14 14:36:26 by runo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//corregirr comportamiento env
int builtin_env(t_env *env)
{
	while(env)
	{
		if(env->value)
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return(0);
}
