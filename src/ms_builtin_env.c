/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/11 18:44:23 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	too_many_arguments(char **str)
{
	if (str[1])
	{
		ft_putstr_fd("env: ‘", 2);
		ft_putstr_fd(str[1], 2);
		ft_putendl_fd("’: No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	alt_env(char **str, char **envp)
{
	int	i;

	(void)envp;
	if (too_many_arguments(str))
		return ;
	i = -1;
	while (envp[++i])
		ft_putendl_fd(envp[i], 1);
}
