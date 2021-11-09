/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/08 23:12:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alt_echo(char **cmd)
{
	int	i;
	int	new_line;
	int	printed_a_line;

	i = 0;
	new_line = 1;
	printed_a_line = 0;
	if (cmd)
	{
		while (cmd[++i])
		{
			if (ft_strncmp(cmd[i], "-n", 3) == 0 && !printed_a_line)
			{
				new_line = 0;
				continue ;
			}
			ft_putstr_fd(cmd[i], 1);
			printed_a_line = 1;
			if (cmd[i + 1])
				ft_putstr_fd(" ", 1);
		}
	}
	if (new_line)
		ft_putstr_fd("\n", 1);
}
