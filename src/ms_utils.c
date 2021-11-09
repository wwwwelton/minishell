/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:37:37 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/09 10:54:28 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_matrix(char ***cmd)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cmd[++i])
	{
		ftex_minprintf("===== COMMAND %d ======\n\n", i + 1);
		while (cmd[++j])
			ftex_minprintf("%s\n", cmd[i][j]);
	}
	j = -1;
}

void	debug(t_data *data)
{
	print_matrix(data->cmd);
}
