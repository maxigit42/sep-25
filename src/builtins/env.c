/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:17 by mwilline          #+#    #+#             */
/*   Updated: 2025/09/17 18:46:00 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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