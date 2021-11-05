/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:37:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/05 00:11:59 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

extern char	**__environ;
typedef struct s_builtin
{
	char		*name;
	void		(*f)(char *);
	struct s_builtin	*next;
}	t_builtin;

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>

void	launch(t_builtin **head);
void	printfunctions(t_builtin *head);

#endif
