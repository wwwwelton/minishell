/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_system.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/26 01:30:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_system(int *fd_tmp, t_data *data, int i)
{
	int			exit_code;
	int			fd[2];
	pid_t		pid;
	t_sigaction	action;

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		dup_in(fd_tmp, data, i);
		dup_out(fd, data, i);
		close(fd[0]);
		if (execve(data->accesspath[i], data->cmd[i], data->alt_env) == -1)
			exit_code = p_error(data->cmd[i][0]);
	}
	init_sigaction(&action, &sig_ign, SIGINT);
	init_sigaction(&action, &sig_ign, SIGQUIT);
	waitpid(pid, &exit_code, 0);
	fd_tmp[0] = fd[0];
	close(fd[1]);
	write_to_files(data, i);
	return (exit_code);
}
