/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:59:36 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/07 02:04:45 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniminishell.h"

// function for parsing command words
void	parseSpace(char* str, char** parsed)
{
	int i;

	for (i = 0; i < 100; i++)
	{
		parsed[i] = strsep(&str, " ");

		if (parsed[i] == NULL)
			break ;
		if (strlen(parsed[i]) == 0)
			i--;
	}
}
