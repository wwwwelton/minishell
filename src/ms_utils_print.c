/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:52:33 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/19 22:45:50 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_matrix(char ***cmd)
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
			ftex_minprintf("%s|\n", cmd[i][j]);
		j = -1;
	}
}

void	printsplit(char **split, char *header)
{
	int	i;

	i = -1;
	ftex_minprintf("========= %s ========\n\n", header);
	while (split[++i])
		ftex_minprintf("%s\n", split[i]);
	ft_putchar_fd('\n', 1);
}

void	debug(t_data *data)
{
	print_matrix(data->cmd);
}
