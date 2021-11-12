/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:12:50 by wleite            #+#    #+#             */
/*   Updated: 2021/11/11 19:26:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_env2(char	*alt_env[200], char **envp)
{
	int	i;

	i = -1;
	while (++i < 200)
		alt_env[i] = NULL;
	i = -1;
	while(envp[++i])
		alt_env[i] = ft_strdup(envp[i]);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	*alt_env[200];

	(void)argc;
	init_env2(alt_env, envp);
	alt_export(argv, alt_env);
	i = -1;
	while (++i < 200)
		ftex_null_ptr((void *)&alt_env[i]);
	return (0);
}
