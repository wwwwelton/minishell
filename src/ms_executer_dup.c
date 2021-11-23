/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/23 04:44:28 by wleite           ###   ########.fr       */
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
				here_doc(fd_tmp, data, i, j);
			if (file_in)
				read_doc(file_in, fd_tmp, fd);
			j++;
		}
	}
	dup42(fd_tmp[0], STDIN_FILENO);
	return (0);
}

int	dup_out(int *fd, t_data *data, int i)
{
	int	file_out;

	if (data->cmd[i + 1])
		dup42(fd[1], STDOUT_FILENO);
	if (data->cmd[i + 1] == NULL && data->flags[i]->file_out)
	{
		file_out = open(data->flags[i]->file_out,
				O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup42(file_out, STDOUT_FILENO);
	}
	return (0);
}
