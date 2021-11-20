/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/20 19:20:19 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dup_in(int *fd_tmp, t_data *data, int i)
{
	int	file_in;

	if (data->flags[i]->file_in)
	{
		file_in = open(data->flags[i]->file_in, O_RDONLY);
		if (file_in < 0)
			perror("open");
		dup42(file_in, STDIN_FILENO);
	}
	else
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
		if (file_out < 0)
			perror("open");
		dup42(file_out, STDOUT_FILENO);
	}
	return (0);
}

void	here_doc(int *fd_tmp, t_data *data, int i)
{
	int		file;

	file = open(TMP_FILE, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (file < 0)
		perror("open");
	if (i > 0)
		read_previous_pipe(fd_tmp[0], file);
	read_std_input(data->flags[i]->file_in, file);
	free(data->flags[i]->file_in);
	data->flags[i]->file_in = ft_strdup(TMP_FILE);
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
