/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:06:25 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/27 16:43:49 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prefix_cwd(char *cwd)
{
	int	cwdsize;

	cwdsize = 100;
	cwd = (char *)ft_calloc(sizeof(char), cwdsize);
	cwd = getcwd(cwd, cwdsize);
	cwd = ftex_strmerge(cwd, ft_strdup("$ "));
	return (cwd);
}

char	*prompt_loop(char *line, char **lastline)
{
	t_sigaction	action;
	char		*cwd;

	cwd = NULL;
	cwd = prefix_cwd(cwd);
	init_sigaction(&action, &sig_prompt, SIGINT);
	init_sigaction(&action, SIG_IGN, SIGQUIT);
	while (!line)
	{
		line = readline(cwd);
		if (!validate_line(line, lastline))
		{
			if (!line)
			{
				ft_putchar_fd('\n', 1);
				exit(1);
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

char	*prompt(char **lastline, char **envp)
{
	static char	buf[BUFFER_SIZE];
	char		*line;
	char		*tmp;

	line = NULL;
	if (!*buf)
		line = prompt_loop(line, lastline);
	else
		line = fetch_buffer(buf, line, lastline, envp);
	if (is_multiple_commands(line))
		store_commands(line, buf);
	tmp = line;
	line = ft_strtrim(line, " ");
	free(tmp);
	return (line);
}
