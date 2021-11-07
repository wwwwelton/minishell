/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:28:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/07 03:04:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniminishell.h"

int	main(void)
{
	char	inputString[1000];
	char	*parsedArgs[100];
	char	*parsedArgsPiped[100];
	int		execFlag = 0;

	init_shell();
	while (1)
	{
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
	}
	return (0);
}
