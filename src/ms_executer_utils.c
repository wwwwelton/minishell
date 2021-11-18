/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/18 02:26:13 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_std_input(char *limiter, int file)
{
	int		fd[2];
	char	*tmp;

	pipe(fd);
	dup2(STDIN_FILENO, fd[0]);
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
