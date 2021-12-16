/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:21:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/16 02:43:42 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_size(char *line, char quote)
{
	int	i;

	i = 1;
	while (line[i] && line[i] != quote)
			i++;
	return (i);
}

char	*restore_line(t_pat *pat, char *line)
{
	pat->i = 0;
	if (!pat->backup[0])
		return (line);
	while (pat->backup[pat->i])
	{
		line = ftex_str_replace
			(line, pat->holder[pat->i], pat->backup[pat->i]);
		free(pat->backup[pat->i]);
		free(pat->holder[pat->i]);
		pat->backup[pat->i] = NULL;
		pat->holder[pat->i] = NULL;
		pat->i++;
	}
	pat->i = 0;
	return (line);
}

char	*apply_token(t_pat *pat, char *line, char *tmp, int size)
{
	pat->backup[pat->i] = ft_substr(tmp, 0, size + 1);
	pat->holder[pat->i] = ftex_strmerge
		(ft_strdup((char *)NEWPAT), ft_itoa(pat->i));
	line = ftex_str_replace
		(line, pat->backup[pat->i], pat->holder[pat->i]);
	pat->i++;
	return (line);
}

char	*token_echo(t_pat *pat, char *line)
{
	char	*tmp;
	char	*bkup;
	int		size;

	tmp = ft_strdup(line);
	bkup = tmp;
	pat->i = 0;
	tmp = ft_strnstr(tmp, "echo", ft_strlen(line));
	while (tmp)
	{
		while (tmp && *tmp != '|' && *tmp != '&')
		{
			while (*tmp && ftex_is_in_set(*tmp, "|&\'\"") == false)
				tmp++;
			if (!*tmp || *tmp == '|' || *tmp == '&')
				break ;
			size = echo_size(tmp, *tmp);
			line = apply_token(pat, line, tmp, size);
			tmp += size + 1;
		}
		tmp = ft_strnstr(tmp, "echo", ft_strlen(tmp));
	}
	free(bkup);
	return (line);
}
