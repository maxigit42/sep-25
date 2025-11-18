/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:46:21 by mwilline          #+#    #+#             */
/*   Updated: 2025/11/18 23:23:39 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_display(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (tmp->value)
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		else
			printf("declare -x %s\n", tmp->key);
		tmp = tmp->next;
	}
	return (0);
}

int is_valid_key(const char *s)
{
    int i = 0;

    if (!s || !s[0])
        return (0);

    if (!(ft_isalpha(s[0]) || s[0] == '_'))
        return (0);

    i = 1;
    while (s[i])
    {
        if (!(ft_isalnum(s[i]) || s[i] == '_'))
            return (0);
        i++;
    }
    return (1);
}

int builtin_export(char **args, t_env **env)
{
    int   i;
    char  *sep;
    char  *key;
    char  *value;

    i = 1;
    if (!args[i])
        return (env_display(env));

    while (args[i])
    {
        sep = ft_strchr(args[i], '=');

        if (sep)
        {
            key = ft_substr(args[i], 0, sep - args[i]);

            if (!is_valid_key(key))
            {
                printf("minishell: export: `%s': not a valid identifier\n", args[i]);
                free(key);
                return (1);
            }

            value = ft_strdup(sep + 1);
            set_env_value(env, key, value);
            free(key);
            free(value);
        }
        else
        {
            if (!is_valid_key(args[i]))
            {
                printf("minishell: export: `%s': not a valid identifier\n", args[i]);
                return (1);
            }
            set_env_value(env, args[i], NULL);
        }
        i++;
    }
	return (0);
}

// int	builtin_export(char **args, t_env **env)
// {
// 	int		i;
// 	char	*sep;
// 	char	*key;
// 	char	*value;

// 	i = 1;
// 	if (!args[i])
// 		return (env_display(env));
// 	while (args[i])
// 	{
// 		sep = ft_strchr(args[i], '=');
// 		if (sep)
// 		{
// 			key = ft_substr(args[i], 0, sep - args[i]);
// 			value = ft_strdup(sep + 1);
// 			set_env_value(env, key, value);
// 			free(key);
// 			free(value);
// 		}
// 		// else
// 		// 	set_env_value(env, args[i], NULL);
// 		i++;
// 	}
// 	return (0);
// }
