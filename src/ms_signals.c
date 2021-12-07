/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:33:05 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/07 15:31:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_prompt(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		set_env_val("?", "130", g_envp);
	}
}

void	sig_ign(int sig)
{
	char	c;

	c = '\n';
	if (sig == SIGINT || sig == SIGQUIT)
		tputs(&c, 0, &ms_putchar);
}

void	sig_heredoc(int sig)
{
	if (sig == SIGINT)
		exit(130);
}

void	init_sigaction(t_sigaction *action, void (*handler)(int), int sig)
{
	action->sa_handler = handler;
	action->sa_flags = 0;
	sigemptyset(&action->sa_mask);
	sigaction(sig, action, NULL);
}
