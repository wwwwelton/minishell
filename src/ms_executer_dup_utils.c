/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer_dup_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/23 04:46:47 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	here_doc(int *fd_tmp, t_data *data, int i, int j)
{
	int		file;
	char	*limiter;

	limiter = data->flags[i]->redir_in[j].file_in;
	file = open(TMP_FILE, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd_tmp[0] != STDIN_FILENO)
		read_previous_pipe(fd_tmp[0], file);
	read_std_input(limiter, file);
	free(limiter);
	data->flags[i]->redir_in[j].file_in = ft_strdup(TMP_FILE);
	close(file);
}

void	read_doc(char *file, int *fd_tmp, int *fd)
{
	int	file_in;

	file_in = open(file, O_RDONLY);
	if (fd_tmp[0] != STDIN_FILENO)
		read_previous_pipe(fd_tmp[0], fd[1]);
	read_previous_pipe(file_in, fd[1]);
	fd_tmp[0] = fd[0];
	close(fd[1]);
}

void	read_std_input(char *limiter, int file)
{
	int		fd[2];
	char	*tmp;

	pipe(fd);
	dup42(STDIN_FILENO, fd[0]);
	while (1)
	{
		ft_putstr_fd("here_doc> ", 1);
		tmp = get_next_line(fd[0]);
		if (ft_strncmp(tmp, limiter, ft_strlen(limiter)) == 0
			&& tmp[ft_strlen(limiter)] == '\n')
		{
			ftex_null_ptr((void *)&tmp);
			close(fd[0]);
			tmp = get_next_line(fd[0]);
			break ;
		}
		ft_putstr_fd(tmp, file);
		ftex_null_ptr((void *)&tmp);
	}
	ftex_null_ptr((void *)&tmp);
}

void	read_previous_pipe(int fd_tmp, int file)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(fd_tmp);
		if (!tmp)
		{
			ftex_null_ptr((void *)&tmp);
			close(fd_tmp);
			tmp = get_next_line(fd_tmp);
			break ;
		}
		ft_putstr_fd(tmp, file);
		ftex_null_ptr((void *)&tmp);
	}
	ftex_null_ptr((void *)&tmp);
}
