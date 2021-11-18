/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer_system.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/18 02:26:52 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	dup_in(int *fd_tmp, t_data *data, int i)
{
	if (data->flags[i]->file_in)
		dup2(open(data->flags[i]->file_in, O_RDONLY), STDIN_FILENO);
	else
		dup2(fd_tmp[0], STDIN_FILENO);
	return (0);
}

static int	dup_out(int *fd, t_data *data, int i)
{
	if (data->cmd[i + 1])
		dup2(fd[1], STDOUT_FILENO);
	if (data->cmd[i + 1] == NULL && data->flags[i]->file_out)
		dup2(open(data->flags[i]->file_out,
			O_CREAT | O_WRONLY | O_TRUNC, 0777), STDOUT_FILENO);
	return (0);
}

static void	here_doc(int *fd_tmp, t_data *data, int i)
{
	int		file;

	file = open(TMP_FILE, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (i > 0)
		read_previous_pipe(fd_tmp[0], file);
	read_std_input(data->flags[i]->file_in, file);
	free(data->flags[i]->file_in);
	data->flags[i]->file_in = ft_strdup(TMP_FILE);
}

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
