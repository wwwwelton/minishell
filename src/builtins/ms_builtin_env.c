/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/12/11 05:15:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	too_many_arguments(char **str)
{
	if (str && str[1])
	{
		ft_putstr_fd("env: ‘", 2);
		ft_putstr_fd(str[1], 2);
		ft_putendl_fd("’: No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	alt_env(char **str, t_data *data)
{
	int	i;

	if (too_many_arguments(str))
		return (EXIT_FAILURE);
	i = 0;
	while (data->alt_env[++i])
		ft_putendl_fd(data->alt_env[i], 1);
	return (EXIT_SUCCESS);
}
