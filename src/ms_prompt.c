/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:06:25 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/21 12:47:36 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	equal_last_line(char *line, char **lastline)
{
	if (!*lastline)
	{
		*lastline = ft_strdup(line);
		return (0);
	}
	if (!ft_strncmp(line, *lastline, ft_strlen(*lastline)))
		return (1);
	free(*lastline);
	*lastline = ft_strdup(line);
	return (0);
}

char	*prompt_user(char **lastline)
{
	char	*line;
	char	*cwd;
	char	*tmp;
	int		cwdsize;

	line = NULL;
	cwdsize = 100;
	cwd = (char *)ft_calloc(sizeof(char), cwdsize);
	cwd = getcwd(cwd, cwdsize);
	cwd = ftex_strmerge(cwd, ft_strdup("$ "));
	while (!line)
	{
		line = readline(cwd);
		if (!validate_line(line))
			ftex_null_ptr((void **)&line);
	}
	free(cwd);
	tmp = line;
	line = ft_strtrim(line, " ");
	free(tmp);
	if (equal_last_line(line, lastline) == 0)
		add_history(line);
	return (line);
}
