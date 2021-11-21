/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/21 12:43:34 by jofelipe         ###   ########.fr       */
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

	line = prompt_user(&data->lastline);
	parser(data, line);
	translate(data->pat, data->cmd, data->alt_env);
	executer(data);
	if (DEBUG)
		debug(data);
	reinit(data);
}
