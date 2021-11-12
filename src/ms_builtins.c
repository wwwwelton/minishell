/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:45:49 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/12 03:00:13 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//copy bash behaviour
void	alt_minishell(char *str)
{
	ftex_minprintf("%s", str);
	// int	pid;

	// pid = fork();
	//if (pid == 0)
	//	execve(minishell)
	// wait(NULL);
}
