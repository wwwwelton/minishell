/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser_pat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:11:44 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/10 10:11:51 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*single_quotes(t_patterns *patterns, char *line, int i)
{
	// ftex_minprintf("%s\n", patterns->backup[patterns->i]);
	patterns->backup[patterns->i] = \
	ft_substr(line, i, ft_strchr(&line[i] + 1, SQUOTES) - &line[i] + 1);
	ftex_minprintf("%s\n", patterns->backup[patterns->i]);
	patterns->holder[patterns->i] = \
	ftex_strmerge(ft_strdup((char *)NEWPAT), ft_itoa(patterns->i));
	line = ftex_str_replace(line, patterns->backup[patterns->i], patterns->holder[patterns->i]);
	patterns->i++;
	return (line);
}

char	*replace_quoted(t_patterns *patterns, char *line)
{
	int	i;

	i = 0;
	patterns->i = 0;
	while (line[i])
	{
		if (line[i] == SQUOTES)
		{
			line = single_quotes(patterns, line, i);
		}
		// if (line[i] == DQUOTES)
		// 	line = calldouble
		++i;
	}
	return (line);
}
