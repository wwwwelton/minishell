/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:37:37 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/11 14:25:39 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_matrix(char ***cmd)
{
	int	i;
	int	j;

	setbuf(stdout, NULL);
	i = -1;
	j = -1;
	while (cmd[++i])
	{
		ftex_minprintf("===== COMMAND %d ======\n\n", i + 1);
		while (cmd[i][++j])
<<<<<<< HEAD
		{
=======
>>>>>>> 7d1bd3ba83a55cdb10c202a3b5b9e5657d872448
			ftex_minprintf("%s\n", cmd[i][j]);
		}
		j = -1;
	}
}

void	debug(t_data *data)
{
	print_matrix(data->cmd);
}

void	free_splited_mat(char **mat)
{
	int	i;

	i = -1;
	if (mat)
	{
		while (mat[++i])
			ftex_null_ptr((void *)&mat[i]);
		ftex_null_ptr((void *)&mat);
	}
}
