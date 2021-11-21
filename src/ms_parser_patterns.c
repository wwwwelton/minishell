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

char	*single_quotes(t_pat *pat, char *line, int i)
{
	pat->backup[pat->i] = \
	ft_substr(line, i, ft_strchr(&line[i] + 1, SQUOTES) - &line[i] + 1);
	pat->holder[pat->i] = \
	ftex_strmerge(ft_strdup((char *)NEWPAT), ft_itoa(pat->i));
	line = ftex_str_replace(line, pat->backup[pat->i], pat->holder[pat->i]);
	pat->i++;
	return (line);
}

char	*double_quotes(t_pat *pat, char *line, int i)
{
	pat->backup[pat->i] = \
	ft_substr(line, i, ft_strchr(&line[i] + 1, DQUOTES) - &line[i] + 1);
	pat->holder[pat->i] = \
	ftex_strmerge(ft_strdup((char *)NEWPAT), ft_itoa(pat->i));
	line = ftex_str_replace(line, pat->backup[pat->i], pat->holder[pat->i]);
	pat->i++;
	return (line);
}

static char	**restore_split(t_pat *pat, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strnstr(cmd[i], pat->holder[pat->i], ft_strlen(cmd[i])))
		{
			cmd[i] = \
			ftex_str_replace(cmd[i], pat->holder[pat->i], pat->backup[pat->i]);
			free(pat->backup[pat->i]);
			free(pat->holder[pat->i]);
			pat->backup[pat->i] = NULL;
			pat->holder[pat->i] = NULL;
			pat->i++;
			if (!pat->backup[pat->i])
			{
				pat->i = 0;
				return (cmd);
			}
		}
		else
			i++;
	}
	return (cmd);
}

char	***restore_quoted(t_pat *pat, char ***cmd)
{
	int	i;

	i = 0;
	pat->i = 0;
	if (!pat->backup[0])
		return (cmd);
	while (pat->backup[pat->i])
	{
		cmd[i] = restore_split(pat, cmd[i]);
		i++;
	}
	return (cmd);
}

char	*replace_quoted(t_pat *pat, char *line)
{
	int	i;

	i = 0;
	pat->i = 0;
	while (line[i])
	{
		if (line[i] == SQUOTES)
			line = single_quotes(pat, line, i);
		if (line[i] == DQUOTES)
			line = double_quotes(pat, line, i);
		++i;
	}
	return (line);
}
