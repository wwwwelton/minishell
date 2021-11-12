/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/11 22:57:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alt_export(char **str, char **envp)
{
	int		i;
	char	**tmp;

	if (str && !str[1])
		return (alt_env(str, envp));
	i = 0;
	while (str[++i])
	{
		if (!strchr(str[i], '='))
			continue ;
		tmp = ft_split(str[i], '=');
		set_env(tmp[0], str[i], envp);
		free_splited_mat(tmp);
	}
	alt_env(NULL, envp);
}
