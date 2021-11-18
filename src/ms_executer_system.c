/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer_system.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/18 03:27:59 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_system(int *fd_tmp, t_data *data, int i)
{
	int		fd[2];
	pid_t	pid;
	char	**cmd;
	char	*path;

	cmd = data->cmd[i];
	path = data->accesspath[i];
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
		if (execve(path, cmd, data->alt_env) == -1)
			perror(cmd[0]);
	}
	wait(NULL);
	fd_tmp[0] = fd[0];
	close(fd[1]);
}
