/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:37:37 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/09 10:54:28 by jofelipe         ###   ########.fr       */
=======
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:28:09 by wleite            #+#    #+#             */
/*   Updated: 2021/11/08 16:49:11 by wleite           ###   ########.fr       */
>>>>>>> b80c8878a6865da898686b8e7e85a17e72a0bd39
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
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
=======
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
>>>>>>> b80c8878a6865da898686b8e7e85a17e72a0bd39
}
