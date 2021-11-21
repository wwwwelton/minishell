/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/21 12:46:40 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_not_found(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("command not found", 2);
	return (127);
}

int	p_error(const char *str)
{
	perror(str);
	return (-1);
}

int	dup42(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
	{
		perror("dup2");
		return (-1);
	}
	return (0);
}
