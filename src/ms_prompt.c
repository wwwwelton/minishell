/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:06:25 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/17 01:36:46 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_line(char *line)
{
	int	len;

	if (!line)
	{
		write(1, "\n", 1);
		return (0);
	}
	else if (!*line)
		return (0);
	len = ft_strlen(line);
	while (len--)
	{
		if (line[len] == ' ')
			continue ;
		if (line[len] == '<' || line[len] == '>')
		{
			ft_putstr_fd("zsh: parse error\n", 2);
			return (0);
		}
		break ;
	}
	return (1);
}

char	*prompt_user(void)
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
	add_history(line);
	return (line);
}
