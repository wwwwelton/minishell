/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/24 01:49:40 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dup_in(int *fd_tmp, t_data *data, int i)
{
	int		fd[2];
	int		j;
	int		heredoc;
	char	*file_in;

	j = 0;
	heredoc = data->flags[i]->redir_in[j].heredoc;
	file_in = data->flags[i]->redir_in[j].file_in;
	if (heredoc || file_in)
	{

		while (heredoc || file_in)
		{
			pipe(fd);
			heredoc = data->flags[i]->redir_in[j].heredoc;
			file_in = data->flags[i]->redir_in[j].file_in;
			if (heredoc)
			{
				here_doc(fd_tmp, data, i, j);
				read_here_doc(fd_tmp, fd);
			}
			else if (file_in)
				read_doc(file_in, fd_tmp, fd);
			j++;
		}
	}
	dup2(fd_tmp[0], STDIN_FILENO);
	return (0);
}

int	dup_out(int *fd, t_data *data, int i)
{
	int		fd_out;
	int		out_append;
	char	*file_out;
	char	**next_cmd;

	out_append = data->flags[i]->redir_out[0].out_append;
	file_out = data->flags[i]->redir_out[0].file_out;
	next_cmd = data->cmd[i + 1];
	if (next_cmd)
		dup2(fd[1], STDOUT_FILENO);
	if (!next_cmd && file_out)
	{
		if (out_append)
			fd_out = open(file_out, O_CREAT | O_WRONLY | O_APPEND, 0777);
		else
			fd_out = open(file_out, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup2(fd_out, STDOUT_FILENO);
	}
	return (0);
}
