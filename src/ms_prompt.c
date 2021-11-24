/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:06:25 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/23 22:02:10 by jofelipe         ###   ########.fr       */
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

char	*prefix_cwd(char *cwd)
{
	int	cwdsize;

	cwdsize = 100;
	cwd = (char *)ft_calloc(sizeof(char), cwdsize);
	cwd = getcwd(cwd, cwdsize);
	cwd = ftex_strmerge(cwd, ft_strdup("$ "));
	return (cwd);
}

char	*prompt_loop(char *line)
{
	char	*cwd;

	cwd = NULL;
	cwd = prefix_cwd(cwd);
	while (!line)
	{
		line = readline(cwd);
		if (!validate_line(line))
		{
			if (!line)
			{
				ft_putstr_fd("\n", 1);
				continue ;
			}
			if (*line != 0)
				ft_putstr_fd("\n", 1);
			ftex_null_ptr((void **)&line);
		}
	}
	free(cwd);
	return (line);
}

char	*store_commands(char *line, char *buf)
{
	int	cmd_size;
	int	str_size;

	cmd_size = command_size(line);
	str_size = ft_strlen(line);
	ft_strlcpy(buf, &line[cmd_size], BUFFER_SIZE);
	ft_memset(&line[cmd_size], ' ', str_size - cmd_size);
	return (line);
}

char	*prompt_user(char **lastline)
{
	static char buf[BUFFER_SIZE];
	char	*line;
	char	*tmp;

	line = NULL;
	if (!*buf)
		line = prompt_loop(line);
	else
		line = fetch_buffer(buf, line);
	if (is_multiple_commands(line))
		store_commands(line, buf);
	tmp = line;
	line = ft_strtrim(line, " ");
	free(tmp);
	if (equal_last_line(line, lastline) == 0)
		add_history(line);
	return (line);
}
