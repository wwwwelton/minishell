/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/12 03:55:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	alt_pwd(char **str, char **envp)
{
	char	*tmp;

	(void)str;
	tmp = get_env("PWD", envp);
	ft_putendl_fd(&tmp[4], 1);
	ftex_null_ptr((void *)&tmp);
	return (EXIT_SUCCESS);
}
