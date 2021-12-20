/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 02:48:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/20 17:02:43 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*restore_token_echo(t_pat *pat, char *line)
{
	pat->i = 0;
	while (pat->backup[pat->i])
	{
		line = ftex_str_replace(line, pat->holder[pat->i], pat->backup[pat->i]);
		free(pat->backup[pat->i]);
		free(pat->holder[pat->i]);
		pat->backup[pat->i] = NULL;
		pat->holder[pat->i] = NULL;
		pat->i++;
	}
	pat->i = 0;
	return (line);
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
