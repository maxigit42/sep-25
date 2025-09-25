/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:57:41 by mwilline          #+#    #+#             */
/*   Updated: 2025/09/17 19:43:03 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_unset(char **args, t_env **env)
{
    int i = 1;

    while (args[i])
    {
        unset_env_value(env, args[i]);
        i++;
    }
    return (0);
}
