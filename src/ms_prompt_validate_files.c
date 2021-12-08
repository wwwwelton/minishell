/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_validate_files.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 01:43:06 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/08 02:48:58 by jofelipe         ###   ########.fr       */
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
			ft_putstr_fd("Minishell: no such file or directory: ", 2);
			ft_putstr_fd(file, 2);
			free(file);
			return (true);
		}
		free(file);
	}
}
