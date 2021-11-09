/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/09 01:19:01 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alt_pwd(char *str)
{
	int		buff_size;
	char	*cwd;

	(void)str;
	buff_size = 128;
	cwd = NULL;
	while (cwd == NULL)
	{
		cwd = (char *)malloc(sizeof(char) * buff_size);
		if (getcwd(cwd, buff_size) == NULL)
		{
			ftex_null_ptr((void *)&cwd);
			buff_size += 128;
		}
	}
	buff_size += 1;
	ftex_null_ptr((void *)&cwd);
	cwd = (char *)malloc(sizeof(char) * buff_size);
	cwd[buff_size] = '\0';
	if (getcwd(cwd, buff_size))
	{
		ft_putstr_fd(cwd, 1);
		ft_putstr_fd("\n", 1);
	}
	ftex_null_ptr((void *)&cwd);
}
