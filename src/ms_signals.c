/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:33:05 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/12 23:04:44 by wleite           ###   ########.fr       */
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
	if (sig == EXIT_SUCCESS)
	{
		ft_putchar_fd('\n', 1);
		exit(sig);
	}
}

void	sig_child(int sig)
{
	if (sig == SIGINT)
		exit(130);
	if (sig == SIGQUIT && !inside_here_doc())
		exit(131);
}

void	sig_cmd(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		set_env_val("?", "130", g_envp);
	}
	if (sig == SIGQUIT && !inside_here_doc())
	{
		ft_putendl_fd("Quit", 2);
		set_env_val("?", "131", g_envp);
	}
}

void	init_sigaction(t_sigaction *action, void (*handler)(int), int sig)
{
	action->sa_handler = handler;
	action->sa_flags = SA_RESTART;
	sigemptyset(&action->sa_mask);
	sigaction(sig, action, NULL);
}
