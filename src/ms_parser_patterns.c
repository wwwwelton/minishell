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

char	*replace_quotes(char *str)
{
	int		i;
	int		patsize;
	char	*pattern;

	i = 0;
	while (str[i])
	{
		if (str[i] == SQUOTES)
		{
			pattern = ft_substr(str, 0, ft_strchr(str + 1, SQUOTES) - str + 1);
			str = ftex_str_replace(str, pattern, NEWPAT)
		}

	}
}

char	*replace_on_line(char **line, char **backup, char **pat, int *index)
{
	int	i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == SQUOTES)
			*line =
	}
}

void	pattern_machine(char **line, char ***cmd)
{
	static char	*backup[50];
	static char	*pat[50];
	static int	index;

	if (!cmd)
		replace_on_line(line, &backup, &pat, &index);
	if (!line)
	{
		restore_line(cmd, &backup, &pat, &index);
		reset_machine(&backup, &pat, &index);
		index = 0;
	}
}
