/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/08 00:34:34 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup(t_data *data)
{
	// deinit();
	minishell();
}

//initializes the three structs
void init(t_data **data, char *str)
{
	t_data	*node;

	node = (t_data *)malloc(sizeof(t_data));
	*data = node;
	node->presplit = ft_split(str, ' ');
}

void	minishell(void)
{
	char	*cmd;
	t_data	*data;
	int		pid;

	// printdir();

	//while (cmd invalid call function)
		//prompt_user();
	cmd = prompt_user();

	//initializes the three structs and counts the pipes
	init(&data, cmd);

	//translate

	//parsing and checkargs
	parser(data);

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
}
