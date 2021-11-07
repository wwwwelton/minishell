/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:27:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/07 02:02:19 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniminishell.h"

// function for finding pipe
int	parsePipe(char* str, char** strpiped)
{
	int i;
	for (i = 0; i < 2; i++)
	{
		strpiped[i] = strsep(&str, "|");
		if (strpiped[i] == NULL)
			break ;
	}
	if (strpiped[1] == NULL)
		return (0); // returns zero if no pipe is found.
	else
	{
		return (1);
	}
}
