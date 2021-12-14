/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_validate_files.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 01:43:06 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/14 03:55:13 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*filename(char *line)
{
	char	*ret;
	int		i;

	i = 0;
	line++;
	while (*line == ' ' && *line)
		line++;
	while (line[i] != ' ' && line[i])
		i++;
	ret = ft_substr(line, 0, i);
	return (ret);
}

t_bool	is_file_invalid(char *line)
{
	char	*file;

	while (1)
	{
		file = ft_strchr(line, '<');
		if (!file)
			return (false);
		line += file - line + 2;
		if (file[1] == '<')
			continue ;
		file = filename(file);
		if (access(file, R_OK))
		{
			ft_putstr_fd("minishell: no such file or directory: ", 2);
			ft_putendl_fd(file, 2);
			free(file);
			set_env_val("?", "1", g_envp);
			return (true);
		}
		free(file);
	}
}
