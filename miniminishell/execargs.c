/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execargs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:59:36 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/20 18:44:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniminishell.h"

void execArgs(char** parsed)
{
	// Forking a child
	int pid;

	pid = fork();
	if (pid == -1)
	{
		printf("\nFailed forking child..");
		return ;
	}
	else if (pid == 0)
	{
		if (execvp(parsed[0], parsed) < 0)
			printf("\nCould not execute command..");
		exit(0);
	}
	else
	{
		// waiting for child to terminate
		wait(NULL);
		return ;
	}
}

void execArgsPiped(char** parsed, char** parsedpipe)
{
	// 0 is read end, 1 is write end
	int pipefd[2];
	int	p1;
	int	p2;

	if (pipe(pipefd) < 0)
	{
		printf("\nPipe could not be initialized");
		return ;
	}
	p1 = fork();
	if (p1 < 0)
	{
		printf("\nCould not fork");
		return ;
	}

	if (p1 == 0)
	{
		// Child 1 executing..
		// It only needs to write at the write end
		close(pipefd[0]);
		dup42(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		if (execvp(parsed[0], parsed) < 0)
		{
			printf("\nCould not execute command 1..");
			exit(0);
		}
	}
	else
	{
		// Parent executing
		p2 = fork();

		if (p2 < 0)
		{
			printf("\nCould not fork");
			return ;
		}

		// Child 2 executing..
		// It only needs to read at the read end
		if (p2 == 0)
		{
			close(pipefd[1]);
			dup42(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			if (execvp(parsedpipe[0], parsedpipe) < 0)
			{
				printf("\nCould not execute command 2..");
				exit(0);
			}
		}
		else
		{
			// parent executing, waiting for two children
			wait(NULL);
			wait(NULL);
		}
	}
}
