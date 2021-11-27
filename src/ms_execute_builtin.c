/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/27 01:55:37 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	call_builtin(t_builtin *head, char **cmd, t_data *data)
{
	while (head)
	{
		if (!ft_strncmp(head->name, cmd[0], ft_strlen(head->name)))
			return (head->f(cmd, data));
		else
			head = head->next;
	}
	return (0);
}

int	execute_builtin(int *fd_tmp, t_data *data, int i)
{
	int		exit_code;
	int		backup[2];
	int		fd[2];
	char	**cmd;

	backup[0] = dup(STDIN_FILENO);
	backup[1] = dup(STDOUT_FILENO);
	cmd = data->cmd[i];
	if (pipe(fd) == -1)
		perror("pipe");
	dup_in(fd_tmp, data, i);
	dup_out(fd, data, i);
	exit_code = call_builtin(data->head, cmd, data);
	fd_tmp[0] = fd[0];
	close(fd[1]);
	dup2(backup[0], STDIN_FILENO);
	dup2(backup[1], STDOUT_FILENO);
	write_to_files(data, i);
	return (exit_code);
}
