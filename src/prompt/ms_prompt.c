/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:06:25 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/17 13:09:57 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	equal_last_line(char *line, char **lastline)
{
	if (!*lastline)
	{
		*lastline = ft_strdup(line);
		return (false);
	}
	if (!ft_strncmp(line, *lastline, 300))
		return (true);
	free(*lastline);
	*lastline = ft_strdup(line);
	return (false);
}

char	*prefix_cwd(char *cwd)
{
	int	cwdsize;

	cwdsize = 100;
	if (cwd)
		free(cwd);
	cwd = (char *)ft_calloc(sizeof(char), cwdsize);
	cwd = getcwd(cwd, cwdsize);
	paint_cwd(&cwd);
	cwd = ftex_strmerge(cwd, ft_strdup(" "));
	return (cwd);
}

char	*prompt_loop(t_data *data, char *line, char **lastline)
{
	t_sigaction	action;
	char		*cwd;

	cwd = NULL;
	init_sigaction(&action, &sig_prompt, SIGINT);
	init_sigaction(&action, SIG_IGN, SIGQUIT);
	while (!line)
	{
		cwd = prefix_cwd(cwd);
		line = readline(cwd);
		if (!line)
			cleanup(data, SIG_PROMPT);
		if (!equal_last_line(line, lastline) && !is_blank_line(line))
			add_history(line);
		if (!validate_line(data->pat, &line))
			ftex_null_ptr((void **)&line);
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

char	*prompt(t_data *data, char **lastline)
{
	static char	buf[BUFFER_SIZE];
	char		*line;
	char		*tmp;

	line = NULL;
	if (!*buf)
		line = prompt_loop(data, line, lastline);
	else
		line = fetch_buffer(data, buf, line, lastline);
	if (is_multiple_commands(line))
		store_commands(line, buf);
	tmp = line;
	line = ft_strtrim(line, " ");
	free(tmp);
	return (line);
}
