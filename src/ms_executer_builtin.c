/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/20 19:19:02 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	call_builtin(t_builtin *head, char **cmd, char **envp)
{
	while (head)
	{
		if (!ft_strncmp(head->name, cmd[0], ft_strlen(head->name)))
			return (head->f(cmd, envp));
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
	if (data->flags[i]->heredoc)
		here_doc(fd_tmp, data, i);
	dup_in(fd_tmp, data, i);
	dup_out(fd, data, i);
	exit_code = call_builtin(data->head, cmd, data->alt_env);
	fd_tmp[0] = fd[0];
	close(fd[1]);
	dup42(backup[0], STDIN_FILENO);
	dup42(backup[1], STDOUT_FILENO);
	return (exit_code);
}
