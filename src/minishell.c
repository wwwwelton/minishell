/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/18 01:58:45 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	cleanup(t_data *data)
// {
// 	//cleans everything before exiting the program
// }

void	minishell(t_data *data)
{
	char	*line;
	int		pid;
	int		i;

	line = prompt_user();
	parser(data, line);
	translate(data->pat, data->cmd, data->alt_env);
	executer(data);
	if (DEBUG)
		debug(data);
	reinit(data);
}
