/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/12 16:50:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_new_line(int flag)
{
	if (flag)
		ft_putstr_fd("\n", 1);
}

int	alt_echo(char **str, char **envp)
{
	int	i;
	int	new_line;
	int	printed_a_line;

	(void)envp;
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
	print_new_line(new_line);
	return (EXIT_SUCCESS);
}
