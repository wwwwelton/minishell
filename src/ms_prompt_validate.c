/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:26:22 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/23 22:09:47 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

int	is_incorrect_redirection(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (len--)
	{
		if (line[len] == ' ')
			continue ;
		if (line[len] == '<' || line[len] == '>')
		{
			ft_putstr_fd("minishell: parse error", 2);
			return (1);
		}
		break ;
	}
	return (0);
}

int	is_odd_quotes(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!line)
		return (1);
	while (*line)
	{
		if (*line == DQUOTES)
			++i;
		else if (*line == SQUOTES)
			++j;
		++line;
	}
	if (i % 2 || j % 2)
	{
		ft_putstr_fd("minishell: close your quotes", 2);
		return (1);
	}
	return (0);
}

int	equal_last_line(char *line, char **lastline)
{
	if (!*lastline)
	{
		*lastline = ft_strdup(line);
		return (0);
	}
	if (!ft_strncmp(line, *lastline, ft_strlen(*lastline)))
		return (1);
	free(*lastline);
	*lastline = ft_strdup(line);
	return (0);
}

int	validate_line(char *line, char **lastline)
{
	if (equal_last_line(line, lastline) == 0)
		add_history(line);
	if (is_blank_line(line))
		return (0);
	if (is_incorrect_redirection(line))
		return (0);
	if (is_odd_quotes(line))
		return (0);
	return (1);
}
