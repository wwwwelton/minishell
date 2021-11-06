/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:45:49 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/06 09:22:18 by jofelipe         ###   ########.fr       */
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

void	alt_echo(char *str)
{
	ftex_minprintf("%s", str);
}

void	alt_cd(char *str)
{
	ftex_minprintf("%s", str);
}

void	alt_pwd(char *str)
{
	ftex_minprintf("%s", str);
}
