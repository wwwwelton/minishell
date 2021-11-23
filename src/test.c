/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:04:31 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/22 22:48:44 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute(int *fd)
{
	char **ls;
	char **path;
	char *access = "/bin/ls";

	path = (char **)malloc(sizeof(char *) * 2);
	path[0] = "ls";
	path[1] = NULL;
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	execve(access, path, NULL);
}

int	main(void)
{
	int	pid;
	int	fd[2];
	char *line;
	char *res;
	char **split;

	res = ft_strdup("");
	pipe(fd);
	pid = fork();
	if (pid == 0)
		execute(fd);
	close(fd[1]);
	while (line)
	{
		line = get_next_line(fd[0]);
		if (line)
			res = ftex_strmerge(res, line);
	}
	ftex_tr(res, '\n', ' ');
	ftex_minprintf("%s\n", res);
}
