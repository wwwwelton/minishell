/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/12/14 04:04:28 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_not_found(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("command not found", 2);
	return (127);
}

int	p_error(const char *str)
{
	perror(str);
	exit (-1);
}

void	here_doc_eof_handler(char *limiter)
{
	fd_collector();
	ft_putstr_fd("minishell: warning: here-document"
		"at line 1 delimited by end-of-file", 1);
	ft_putstr_fd(" (wanted `", 1);
	ft_putstr_fd(limiter, 1);
	ft_putstr_fd("')", 1);
	ft_putstr_fd("\n", 1);
	exit (0);
}
