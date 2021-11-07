/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniminishell.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:27:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/07 03:05:24 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMINISHELL_H
# define MINIMINISHELL_H

# include "libft.h"
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/wait.h>

# define clear() printf("\033[H\033[J")

int		builtin(char **parsed);
int		processString(char *str, char **parsed, char **parsedpipe);
int		takeInput(char* str);
int		parsePipe(char* str, char** strpiped);
void	execArgs(char** parsed);
void	execArgsPiped(char** parsed, char** parsedpipe);
void	openHelp(void);
void	parseSpace(char* str, char** parsed);
void	printDir(void);
void	init_shell(void);

#endif
