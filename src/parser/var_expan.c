#include "minishell.h"

static int	get_var_name_len(char *str)
{
	int	len;

	len = 0;
	if (str[len] == '?')
		return (1);
	if (!ft_isalpha(str[len]) && str[len] != '_')
		return (0);
	while (str[len] && (ft_isalnum(str[len]) || str[len] == '_'))
		len++;
	return (len);
}

static char	*get_var_name(char *str, int len)
{
	char	*name;

	if (len <= 0)
		return (NULL);
	name = malloc(len + 1);
	if (!name)
		return (NULL);
	ft_strlcpy(name, str, len + 1);
	return (name);
}

// static int	handle_special_dollar(char *str, char *result, int j)
// {
// 	if (str[1] == '\0' || str[1] == ' ' || str[1] == '\t')
// 	{
// 		result[j++] = '$';
// 		return (j);
// 	}
// 	if (ft_isdigit(str[1]) || str[1] == '@' || str[1] == '*' || str[1] == '#')
// 		return (j);
// 	result[j++] = '$';
// 	return (j);
// }

static int calculate_expanded_len(char *str, t_env *env, int exit_status)
{
    int len = 0;
    int i = 0;
    char quote = 0;

    if (!str)
        return 0;

    while (str[i])
    {
        /* gestionar comillas */
        if ((str[i] == '\'' || str[i] == '"') && !quote)
        {
            quote = str[i++];
            continue;
        }
        if (str[i] == quote)
        {
            quote = 0;
            i++;
            continue;
        }

        /* expansion: solo si siguiente caracter existe y no estamos en comilla simple */
        if (str[i] == '$' && str[i + 1] && quote != '\'')
        {
            int var_len = get_var_name_len(&str[i + 1]);

            if (var_len == 0)
            {
                /* caso: no hay nombre de variable -> se interpretará como '$' literal */
                len++;
                i++;              /* avanzamos 1 (el '$') */
                continue;
            }

            if (str[i + 1] == '?')
            {
                char *exit_str = ft_itoa(exit_status);
                if (exit_str)
                {
                    len += ft_strlen(exit_str);
                    free(exit_str);
                }
                i += 2;           /* saltamos '$' y '?' */
                continue;
            }

            /* nombre normal: obtener longitud del valor si existe */
            {
                char *name = get_var_name(&str[i + 1], var_len);
                if (name)
                {
                    char *val = get_env_value_list(env, name);
                    if (val)
                        len += ft_strlen(val);
                    free(name);
                }
            }
            i += var_len + 1; /* saltamos '$' + nombre */
            continue;
        }

        /* caso normal: un carácter */
        len++;
        i++;
    }
    return len;
}

// static int	expand_var(char *str, char *result, int j, t_data *data)
// {
// 	int		var_len;
// 	char	*name;
// 	char	*value;

// 	var_len = get_var_name_len(&str[1]);
// 	if (var_len == 0)
// 		return (handle_special_dollar(str, result, j));
// 	if (str[1] == '?')
// 	{
// 		char *exit_str = ft_itoa(data->exit_status);
// 		ft_strlcpy(&result[j], exit_str, ft_strlen(exit_str) + 1);
// 		j += ft_strlen(exit_str);
// 		free(exit_str);
// 		return (j);
// 	}
// 	name = get_var_name(&str[1], var_len);
// 	value = get_env_value_list(data->env, name);
// 	if (value)
// 	{
// 		ft_strlcpy(&result[j], value, ft_strlen(value) + 1);
// 		j += ft_strlen(value);
// 	}
// 	free(name);
// 	return (j);
// }

char *expand_variables(char *str, t_data *data)
{
    char *result;
    int i = 0;
    int j = 0;
    char quote = 0;
    int len;

    if (!str)
        return NULL;
    if (str[0] == '\'' && str[ft_strlen(str) - 1] == '\'')
        return ft_strdup(str);

    len = calculate_expanded_len(str, data->env, data->exit_status);
    result = malloc(len + 1);
    if (!result)
        return NULL;

    while (str[i])
    {
        /* comillas */
        if ((str[i] == '\'' || str[i] == '"') && !quote)
        {
            quote = str[i++];
            continue;
        }
        if (str[i] == quote)
        {
            quote = 0;
            i++;
            continue;
        }

        /* expansión solo fuera de comillas simples y si hay siguiente char */
        if (str[i] == '$' && str[i + 1] && quote != '\'')
        {
            int var_len = get_var_name_len(&str[i + 1]);

            if (var_len == 0)
            {
                /* $ seguido de nada válido → copia literal '$' */
                result[j++] = '$';
                i++;
                continue;
            }

            if (str[i + 1] == '?')
            {
                char *exit_str = ft_itoa(data->exit_status);
                if (exit_str)
                {
                    ft_strlcpy(&result[j], exit_str, ft_strlen(exit_str) + 1);
                    j += ft_strlen(exit_str);
                    free(exit_str);
                }
                i += 2;
                continue;
            }

            /* variable normal */
            {
                char *name = get_var_name(&str[i + 1], var_len);
                if (name)
                {
                    char *val = get_env_value_list(data->env, name);
                    if (val)
                    {
                        ft_strlcpy(&result[j], val, ft_strlen(val) + 1);
                        j += ft_strlen(val);
                    }
                    free(name);
                }
            }
            i += var_len + 1;
            continue;
        }

        /* carácter normal */
        result[j++] = str[i++];
    }
    result[j] = '\0';
    return result;
}

char **process_tokens(char **tokens, t_data *data)
{
    char **processed;
    int i;

    if (!tokens)
        return (NULL);
    for (i = 0; tokens[i]; i++);
    processed = malloc(sizeof(char *) * (i + 1));
    if (!processed)
        return (NULL);

    i = 0;
    while (tokens[i])
    {
        char *t = tokens[i];
        if (t[0] == '\'' && t[ft_strlen(t) - 1] == '\'')
            processed[i] = ft_strdup(t); // no expandir
        else
            processed[i] = expand_variables(t, data);

        if (!processed[i])
        {
            while (--i >= 0)
                free(processed[i]);
            free(processed);
            return (NULL);
        }
        i++;
    }
    processed[i] = NULL;
    return (processed);
}

