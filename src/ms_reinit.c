/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_reinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:46:16 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/24 00:09:44 by jofelipe         ###   ########.fr       */
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

void	cleanup(t_data *data)
{
	int	i;

	reinit(data);
	deinit_builtins(data->head);
	free(data->pat);
	i = -1;
	while (data->alt_env[++i])
		free(data->alt_env[i]);
	free(data);
	exit(EXIT_SUCCESS);
}

void	reinit(t_data *data)
{
	int	i;

	i = -1;
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
		free(data->flags[i]);
	free(data->flags);
	data->flags = NULL;
	i = -1;
	while (data->cmd[++i])
		free_splited_mat(data->cmd[i]);
	free(data->cmd);
	data->cmd = NULL;
}
