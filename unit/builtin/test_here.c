/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_here.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:12:50 by wleite            #+#    #+#             */
/*   Updated: 2021/11/17 22:08:42 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_std_input(int *fd, char *limiter)
{
	int		backup;
	char	*tmp;

	backup = dup(fd[0]);
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
		ft_putstr_fd(tmp, fd[1]);
		ftex_null_ptr((void *)&tmp);
	}
	ftex_null_ptr((void *)&tmp);
	dup2(backup, fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	char	*temp;

	pipe(fd);
	(void)argc;
	(void)argv;
	(void)envp;

	read_std_input(fd, "END");
	read_std_input(fd, "END1");

	while(1)
	{
		temp = get_next_line(fd[0]);
		if (!temp)
		break ;
		printf("%s", temp);
		free(temp);
		close(fd[0]);
	}

	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd[2];
// 	char	*temp;

// 	pipe(fd);
// 	(void)argc;
// 	(void)argv;
// 	(void)envp;

// 	read_std_input(fd, "END");
// 	read_std_input(fd, "END1");

// 	while(1)
// 	{
// 		temp = get_next_line(fd[0]);
// 		if (!temp)
// 		break ;
// 		printf("%s", temp);
// 		free(temp);
// 		close(fd[0]);
// 	}

// 	return (0);
// }
