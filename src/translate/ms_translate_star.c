/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_translate_star.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:02:28 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/13 05:44:34 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_ls(int *fd, char *access, char **cmd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	fd_collector();
	execve(access, cmd, NULL);
}

static char	*get_files(int fd)
{
	char	*res;
	char	*line;

	line = "INIT";
	res = ft_strdup("");
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			res = ftex_strmerge(res, line);
	}
	ftex_tr(res, "\n\t", " ");
	close (fd);
	return (res);
}

static char	*fetch_ls(void)
{
	int		pid;
	int		fd[2];
	char	**cmd;
	char	*access;

	access = "/bin/ls";
	cmd = (char **)malloc(sizeof(char *) * 2);
	cmd[0] = ft_strdup("ls");
	cmd[1] = NULL;
	pipe(fd);
	pid = fork();
	if (pid == 0)
		exec_ls(fd, access, cmd);
	wait(NULL);
	close(fd[1]);
	free_splited_mat(cmd);
	return (get_files(fd[0]));
}

char	*find_stars(char *line)
{
	char	*files;

	if (!ft_strchr(line, '*'))
		return (line);
	files = fetch_ls();
	line = ftex_str_replace(line, "*", files);
	free(files);
	return (line);
}
