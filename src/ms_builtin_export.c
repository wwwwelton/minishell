/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/12 18:11:32 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	alt_export(char **str, char **envp)
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
	return (0);
}
