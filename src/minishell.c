/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/15 23:00:46 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup(t_data *data)
{
	//cleans everything before exiting the program
}

void reinit(t_data *data, char *str)
{
	//prepares to read the next line
	//frees whatever was used by the previous line
	//reinitializes these used parameters as NULL
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


	//parsing and checkargs
	parser(data, line);

	//translate
	data->cmd = translate(data->pat, data->cmd, data->alt_env);

	//checkargs

	//execute parsed commands
	//executecommands(data);
	int i = 0;
	while (data->cmd[i])
	{
		pid = fork();
		if (pid == 0)
			execve(data->accesspath[i], data->cmd[i], g_environ);
		wait(NULL);
		i++;
	}

	if (DEBUG)
		debug(data);
	// reinit(data, line);
}
