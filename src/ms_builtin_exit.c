/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/27 01:51:42 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	too_many_arguments(char **str)
{
	if (str && str[1] && str[2])
	{
		ft_putendl_fd("exit: too many arguments", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

static void	printf_invalid_parameter(char *str)
{
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": numeric argument required", 2);
}

int	alt_exit(char **str, t_data *data)
{
	(void)data;
	if (too_many_arguments(str))
		exit (EXIT_FAILURE);
	if (str[1] && !is_numeric(str[1]))
	{
		printf_invalid_parameter(str[1]);
		exit(EXIT_FAILURE);
	}
	else if (str[1])
		exit(ft_atoi(str[1]));
	else
		exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
