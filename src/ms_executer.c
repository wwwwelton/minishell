/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/18 02:27:25 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executer(t_data *data)
{
	int		i;
	int		fd_tmp;

	i = -1;
	fd_tmp = STDIN_FILENO;
	while (data->cmd[++i])
	{
		if (data->flags[i]->system_cmd)
			execute_system(&fd_tmp, data, i);
		unlink(TMP_FILE);
	}
	return (0);
}
