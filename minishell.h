/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:37:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/02 22:37:26 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

extern char	**__environ;
typedef struct s_builtin
{
	char	*name;
	void	(*f)(char **cmd);
}	t_builtin;

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>

#endif
