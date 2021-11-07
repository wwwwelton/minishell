/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:28:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/07 02:05:38 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniminishell.h"

int	processString(char *str, char **parsed, char **parsedpipe)
{
	char	*strpiped[2];
	int		piped = 0;

	piped = parsePipe(str, strpiped);

	if (piped)
	{
		parseSpace(strpiped[0], parsed);
		parseSpace(strpiped[1], parsed);
	}
	else
		parseSpace(str, parsed);
	if (builtin(parsed))
		return (0);
	else
		return (1 + piped);
}
