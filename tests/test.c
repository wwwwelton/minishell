/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:04:31 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/25 03:58:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <curses.h>
#include <term.h>

int	putcharaction(int c)
{
	return(write(1, &c, 0));
}

void	act(int sig)
{
	// char	*str = "hello";
	char	str[1];

	str[0] = (char)-110;
	tputs(str, 0, &ft_putchar_fd);
}
int	main(void)
{
	t_sigaction action;
	char	*str;

	// setupterm(NULL, 1, NULL);
	ftex_minprintf("%d\n", EOF);
	action.sa_handler = &act;
	sigaction(SIGINT, &action, NULL);
	action.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &action, NULL);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			ft_putstr_fd("null returned\n", 2);
			break ;
		}
	}

}

// void	execute(int *fd)
// {
// 	char	**ls;
// 	char	**path;
// 	char	*access;

// 	access = "/bin/ls";
// 	path = (char **)malloc(sizeof(char *) * 2);
// 	path[0] = "ls";
// 	path[1] = NULL;
// 	close(fd[0]);
// 	dup2(fd[1], STDOUT_FILENO);
// 	execve(access, path, NULL);
// }

// int	main(void)
// {
// 	int		pid;
// 	int		fd[2];
// 	char	*line;
// 	char	*res;

// 	res = ft_strdup("");
// 	pipe(fd);
// 	pid = fork();
// 	if (pid == 0)
// 		execute(fd);
// 	close(fd[1]);
// 	while (line)
// 	{
// 		line = get_next_line(fd[0]);
// 		if (line)
// 			res = ftex_strmerge(res, line);
// 	}
// 	ftex_tr(res, '\n', ' ');
// 	ftex_minprintf("%s\n", res);
// }
