/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:33:05 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/24 08:59:28 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_prompt(int sig)
{
	ftex_minprintf("%d", sig);
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT || sig == SIGKILL || sig == SIGTERM)
	{
		exit(1);
	}
}

void	sig_exec(int sig)
{
	ftex_minprintf("%d", sig);
}

void	sig_heredoc(int sig)
{
	ftex_minprintf("%d", sig);
}

void	init_sigaction(struct sigaction *action, void (*handler)(int), int sig)
{
	action->sa_handler = handler;
	sigaction(sig, action, NULL);
}
