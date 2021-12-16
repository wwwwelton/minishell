/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 02:48:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/16 02:25:04 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
