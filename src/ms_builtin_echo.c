/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/11 17:03:43 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alt_echo(char **str)
{
	int	i;
	int	new_line;
	int	printed_a_line;

	i = 0;
	new_line = 1;
	printed_a_line = 0;
	if (str)
	{
		while (str[++i])
		{
			if (ft_strncmp(str[i], "-n", 3) == 0 && !printed_a_line)
			{
				new_line = 0;
				continue ;
			}
			ft_putstr_fd(str[i], 1);
			printed_a_line = 1;
			if (str[i + 1])
				ft_putstr_fd(" ", 1);
		}
	}
	if (new_line)
		ft_putstr_fd("\n", 1);
}
