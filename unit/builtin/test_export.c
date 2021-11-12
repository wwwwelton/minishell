/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:12:50 by wleite            #+#    #+#             */
/*   Updated: 2021/11/12 17:20:10 by wleite           ###   ########.fr       */
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
	int		exit_code;
	char	*alt_env[200];

	(void)argc;
	init_env2(alt_env, envp);
	exit_code = alt_export(argv, alt_env);
	i = -1;
	while (++i < 200)
		ftex_null_ptr((void *)&alt_env[i]);
	return (exit_code);
}
