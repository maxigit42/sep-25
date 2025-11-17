/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+  	+#+           */
/*   Created: 2025/07/08 18:08:59 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/08 19:39:35 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_signal(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	ctrl_c(int sig)
{
	ssize_t	ret;

	(void)sig;
	ret = write(STDERR_FILENO, "\n", 1);
	if (!ret)
		perror("Error");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 130;
}
