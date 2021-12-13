/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_reinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:46:16 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/13 05:44:34 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	deinit_builtins(t_builtin *head)
{
	t_builtin	*prev;

	while (head)
	{
		prev = head;
		free(head->name);
		head = head->next;
		free(prev);
	}
}

void	fd_collector(void)
{
	int	fd;

	fd = open(TMP_FILE, O_RDONLY | O_CREAT);
	close(fd + 1);
	while (fd > 2)
		close(fd--);
	unlink(TMP_FILE);
}

int	cleanup(t_data *data, int code)
{
	int	i;

	if (code == SIG_PROMPT)
		code = EXIT_SUCCESS;
	else
		reinit(data);
	fd_collector();
	deinit_builtins((t_builtin *)data->head);
	free(data->pat);
	free(data->lastline);
	i = -1;
	while (data->alt_env[++i])
		free(data->alt_env[i]);
	free(data);
	exit(code);
	return (0);
}

static void	free_redirs(t_flags *flags)
{
	int	i;

	i = -1;
	while (flags->redir_in[++i].file_in)
		free(flags->redir_in[i].file_in);
	i = -1;
	while (flags->redir_out[++i].file_out)
		free(flags->redir_out[i].file_out);
}

void	reinit(t_data *data)
{
	int	i;

	i = -1;
	fd_collector();
	free_splited_mat(data->presplit);
	free_splited_mat(data->path);
	free_splited_mat(data->accesspath);
	while (data->pat->backup[++i])
		free(data->pat->backup[i]);
	i = -1;
	while (data->pat->holder[++i])
		free(data->pat->holder[i]);
	i = -1;
	while (data->flags[++i])
	{
		free_redirs(data->flags[i]);
		free(data->flags[i]);
	}
	free(data->flags);
	data->flags = NULL;
	i = -1;
	while (data->cmd[++i])
		free_splited_mat(data->cmd[i]);
	free(data->cmd);
	data->cmd = NULL;
}
