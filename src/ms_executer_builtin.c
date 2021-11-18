/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/18 03:26:56 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	call_builtin(t_builtin *head, char **cmd, char **envp)
{
	while (head)
	{
		if (!ft_strncmp(head->name, cmd[0], ft_strlen(head->name)))
		{
			head->f(cmd, envp);
			break ;
		}
		else
			head = head->next;
	}
}

void	execute_builtin(int *fd_tmp, t_data *data, int i)
{
	int		backup[2];
	int		fd[2];
	char	**cmd;

	backup[0] = dup(0);
	backup[1] = dup(1);
	cmd = data->cmd[i];
	pipe(fd);
	if (data->flags[i]->heredoc)
		here_doc(fd_tmp, data, i);
	dup_in(fd_tmp, data, i);
	dup_out(fd, data, i);
	call_builtin(data->head, cmd, data->alt_env);
	fd_tmp[0] = fd[0];
	close(fd[1]);
	dup2(backup[0], 0);
	dup2(backup[1], 1);
}
