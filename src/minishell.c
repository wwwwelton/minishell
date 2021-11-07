/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/07 03:40:18 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//initializes the three structs
void init(t_data **data, char *str)
{
	t_data	*node;

	node = (t_data *)malloc(sizeof(t_data));
	*data = node;
	node->line = str;
}

void	cleanup()
{
	deinit();
	minishell();
}

// char	*prompt_user(char *str)
// {

// }

	// print shell line
	printDir();
	// read input
	if (takeInput(inputString))
		continue ;
	// process
	execFlag = processString(inputString, parsedArgs, parsedArgsPiped);
	// if the no cmd or cmd is built-in returns 0

	// execute commands (pipex?)
	if (execFlag == 1) // single cmd
		execArgs(parsedArgs);
	if (execFlag == 2) // more than 2 commands
		execArgsPiped(parsedArgs, parsedArgsPiped);

void	minishell(void)
{
	char	*cmd;
	t_data	*data;
	int		pid;

	// printdir();

	cmd = NULL;
	ft_putstr_fd("$ ", 1);
	cmd = readline(cmd);
	//initializes the three structs and counts the pipes
	init(&data, cmd);
	if (cmd == NULL || !*cmd)
			minishell();
	//isspace
	add_history(cmd);
	//translate
	//parsing and checkargs
	parser(data, flags, builtins);
	//checkargs
	//execute parsed commands
	executecommands(data);

	pid = fork();
	if (pid == 0)
		execve(data->path, data->cmd[0], g_environ);

}


pipex()
{
	int 	i;

	while (cmd)
}

flags->pipe

flags->fileout = "file1";
	open_file()

echo $USER
