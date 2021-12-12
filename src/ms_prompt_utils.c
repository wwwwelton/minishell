/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 02:48:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/11 22:33:40 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	paint_cwd(char **cwd)
{
	char	*success;

	if (!cwd)
		return ;
	success = get_env_val("?", g_envp);
	if (*success == '0')
	{
		*cwd = ftex_strmerge(*cwd, ft_strdup("😉 "));
		*cwd = ftex_strmerge(ft_strdup("\001\033[1;32m\002"), *cwd);
		*cwd = ftex_strmerge(*cwd, ft_strdup("\001\033[0m\002"));
	}
	else
	{
		*cwd = ftex_strmerge(*cwd, ft_strdup("😡 "));
		*cwd = ftex_strmerge(ft_strdup("\001\033[1;31m\002"), *cwd);
		*cwd = ftex_strmerge(*cwd, ft_strdup("\001\033[0m\002"));
	}
	ftex_null_ptr((void *)&success);
}

char	*check_here_doc_spaces(char *line)
{
	if (ft_strnstr(line, "__0x", ft_strlen(line)))
	{
		line = ftex_str_replace_all(line, "__0xREDIRIN", " < ");
		line = ftex_str_replace_all(line, "__0xREDIROUT", " > ");
		line = ftex_str_replace_all(line, "__0xDOCOUT", " >> ");
		line = ftex_str_replace_all(line, "__0xDOCIN", " << ");
	}
	return (line);
}

char	*check_redir_spaces(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
				line = ftex_str_replace(line, "<<", "__0xDOCIN");
		if (line[i] == '<')
			if (i == 0 || line[i + 1] != ' ' || line[i - 1] != ' ')
				line = ftex_str_replace(line, "<", "__0xREDIRIN");
		if (line[i] == '>' && line[i + 1] == '>')
				line = ftex_str_replace(line, ">>", "__0xDOCOUT");
		if (line[i] == '>')
			if (i == 0 || line[i + 1] != ' ' || line [i - 1] != ' ')
				line = ftex_str_replace(line, ">", "__0xREDIROUT");
	}
	return (line);
}
