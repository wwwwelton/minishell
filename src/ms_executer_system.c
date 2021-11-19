/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer_system.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/19 17:00:00 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_system(int *fd_tmp, t_data *data, int i)
{
	int		exit_code;
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("execute_command");
	else if (pid == 0)
	{
		if (data->flags[i]->heredoc)
			here_doc(fd_tmp, data, i);
		dup_in(fd_tmp, data, i);
		dup_out(fd, data, i);
		close(fd[0]);
		if (execve(data->accesspath[i], data->cmd[i], data->alt_env) == -1)
		{
			perror(data->cmd[i][0]);
			exit_code = -1;
		}
	}
	waitpid(-1, &exit_code, 0);
	fd_tmp[0] = fd[0];
	close(fd[1]);
	return (exit_code);
}
