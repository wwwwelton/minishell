/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/10 17:45:29 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup(t_data *data)
{
	// deinit();
}

//initializes the three structs
void init(t_data *data, char *str)
{
	data->presplit = ft_split(str, ' ');
}

void	minishell(t_data *data)
{
	char	*line;
	int		pid;

	// printdir();

	//while (line invalid call function)
		//prompt_user();
	line = prompt_user();

	//initializes the three structs and counts the pipes
	init(data, line);

	//translate

	//parsing and checkargs
	parser(data, line);

	//checkargs

	//execute parsed commands
	//executecommands(data);

	// ftex_minprintf("%s\n", data->cmd[0][0]);
	// ftex_minprintf("%s\n", data->cmd[0][1]);
	// ftex_minprintf("%s\n", data->accesspath[0]);
	pid = fork();
	if (pid == 0)
		execve(data->accesspath[0], data->cmd[0], g_environ);
	wait(NULL);
	if (DEBUG)
		debug(data);
}
