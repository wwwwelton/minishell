/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:21:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/15 13:51:08 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_in_set(char c, char *set)
{
	if (!set)
		return (false);
	ftex_minprintf("%s\n", set);
	while (*set)
	{
		if (c == *set)
		{
			return (true);
		}
		set++;
	}
	return (false);
}

int	echo_size(char *line, char quote)
{
	int	i;

	i = 1;
	while (line[i] && line[i] != quote)
			i++;
	return (i);
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
	tmp = ft_strnstr(tmp, "echo", ft_strlen(line));
	while (tmp)
	{
		while (tmp && *tmp != '|' && *tmp != '&')
		{
			while (*tmp && is_in_set(*tmp, "|&\'\"") == false)
				tmp++;
			if (!*tmp || *tmp == '|' || *tmp == '&')
				break ;
			size = echo_size(tmp, *tmp);
			line = apply_token(pat, line, tmp, size);
			tmp += size + 1;
		}
		if ((*tmp == '|' && *(tmp + 1) == '|') || *tmp == '&')
			break ;
		tmp = ft_strnstr(tmp, "echo", ft_strlen(tmp));
	}
	free(bkup);
	return (line);
}
