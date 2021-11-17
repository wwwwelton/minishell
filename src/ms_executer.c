/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/16 01:13:37 by wleite           ###   ########.fr       */
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

static void	execute_system(int *fd_tmp, char **cmd, char *path, char **envp, int last)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("execute_command");
	else if (pid == 0)
	{
		dup2(fd_tmp[0], STDIN_FILENO);
		if (!last)
			dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		if (execve(path, cmd, envp) == -1)
			perror(cmd[0]);
	}
	wait(NULL);
	fd_tmp[0] = fd[0];
	close(fd[1]);
}

static void	execute_builtin(int *fd_tmp, char **cmd, char *path, char **envp, int last, t_builtin *head)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("execute_command");
	else if (pid == 0)
	{
		dup2(fd_tmp[0], STDIN_FILENO);
		if (!last)
			dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		call_builtin(head, cmd, envp);
		exit (0);
	}
	wait(NULL);
	fd_tmp[0] = fd[0];
	close(fd[1]);
}

int	executer(t_data *data)
{
	int		i;
	int		j;
	int		last;
	int		fd_tmp;
	char	***cmd;
	char	**path;
	char	**envp;
	t_flags	**flags;

	cmd = data->cmd;
	path = data->accesspath;
	envp = data->alt_env;
	flags = data->flags;
	i = -1;
	j = -1;
	fd_tmp = 0;
	last = 0;
	while (cmd[++i])
	{
		if (cmd[i + 1] == NULL)
			last = 1;
		if (flags[i]->builtins)
			execute_builtin(&fd_tmp, cmd[i], path[i], envp, last, data->head);
		else if (flags[i]->system_cmd)
			execute_system(&fd_tmp, cmd[i], path[i], envp, last);
		printf("%s", get_env("TESTE1", data->alt_env));
	}
	// while (cmd[++i])
	// {
	// 	if (flags[i]->builtins)
	// 		printf("builtin: %s\n", cmd[i][0]);
	// 	if (flags[i]->system_cmd)
	// 		printf("system: %s\n", cmd[i][0]);
	// 	if (flags[i]->file_in)
	// 		printf("file_in: %s\n", flags[i]->file_in);
	// 	if (flags[i]->file_out)
	// 		printf("file_out: %s\n", flags[i]->file_out);
	// 	if (flags[i]->in_append)
	// 		printf("in_append: %d\n", flags[i]->in_append);
	// 	if (flags[i]->out_append)
	// 		printf("out_append: %d\n", flags[i]->out_append);
	// 	if (flags[i]->heredoc)
	// 		printf("heredoc: %d\n", flags[i]->heredoc);
	// }
	// print_matrix(cmd);
	return (0);
}
