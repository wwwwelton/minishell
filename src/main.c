/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:28 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/09 15:50:27 by jofelipe         ###   ########.fr       */
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
	rl_complete('\t', '!');
	rl_complete_internal('\t');
	init_data(&data);
	while (1)
		minishell(data);
	return (0);
}
