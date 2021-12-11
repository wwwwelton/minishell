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

static void	handle_exit_code(pid_t pid, int *exit_code, t_sigaction *action)
{
	init_sigaction(action, &sig_cmd, SIGINT);
	init_sigaction(action, &sig_cmd, SIGQUIT);
	wait(NULL);
	waitpid(pid, exit_code, 0);
	if (WIFEXITED(*exit_code))
		*exit_code = WEXITSTATUS(*exit_code);
	else if (WIFSIGNALED(*exit_code))
		*exit_code = DFL_SIGNAL;
}

static void	set_child_sigaction(t_sigaction *action)
{
	init_sigaction(action, &sig_child, SIGQUIT);
	init_sigaction(action, &sig_child, SIGINT);
}

int	execute_system(int *fd_tmp, t_data *data, int i)
{
	int			exit_code;
	int			fd[2];
	pid_t		pid;
	t_sigaction	action;

	exit_code = DFL_SIGNAL;
	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		set_child_sigaction(&action);
		dup_in(fd_tmp, data, i);
		dup_out(fd, data, i);
		close(fd[0]);
		if (execve(data->accesspath[i], data->cmd[i], data->alt_env) == -1)
			exit_code = p_error(data->cmd[i][0]);
	}
	handle_exit_code(pid, &exit_code, &action);
	fd_tmp[0] = fd[0];
	close(fd[1]);
	write_to_files(data, i);
	return (exit_code);
}
