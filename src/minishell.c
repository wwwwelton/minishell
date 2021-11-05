/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/05 03:32:05 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(void)
{
	char	*cmd;

	cmd = NULL;
	cmd = readline(cmd);
	//isspace
	add_history(cmd);
}
