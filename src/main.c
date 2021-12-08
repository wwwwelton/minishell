/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:28 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/08 18:45:25 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_envp;

int	main(int argc, char **argv, char **envp)
{
	t_data		*data;

	(void)argc;
	(void)argv;
	g_envp = envp;
	init_data(&data);
	while (1)
		minishell(data);
	return (0);
}
