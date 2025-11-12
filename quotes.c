/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runo <runo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:26:55 by runo              #+#    #+#             */
/*   Updated: 2025/11/12 15:55:25 by runo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"


//HAY QUE TERMINAR TODO ESTO

#include <stdio.h>

int	count_quotes(char *str)
{
	
}

static int	count_tokens(char *str)
{
	int i;
	int words;
	int in_word;

	i = 0;
	words = 0;
	in_word = 0;
    while (str[i])
    {
		i += 
        if (str[i] != ' ' && !in_word)
        {
            in_word = 1;
            words++;
        }
        else if (str[i] == ' ')
            in_word = 0;
        i++;
    }
    return (words);
}

char **split_arg_tokens(char *arg)
{
	
}
/*int main()
{
	printf("resultado: %d", count_words("    j j j j j j j j j j       hola buenas noches"));
	return (0);
}*/