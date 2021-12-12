/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:26:22 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/12 06:15:42 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_blank_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (true);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (line[i] == '\0')
		return (true);
	return (false);
}

t_bool	is_incorrect_redirection(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (len--)
	{
		if (line[len] == ' ')
			continue ;
		if (line[len] == '<' || line[len] == '>')
		{
			ft_putstr_fd("minishell: parse error\n", 2);
			set_env_val("?", "1", g_envp);
			return (true);
		}
		break ;
	}
	return (false);
}

t_bool	is_odd_quotes(char *line)
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
		ft_putstr_fd("minishell: close your quotes\n", 2);
		set_env_val("?", "1", g_envp);
		return (true);
	}
	return (false);
}

t_bool	is_empty_pipes(char *line)
{
	int	i;

	i = 0;
	while (line[i++])
	{
		if (line[i] == '|' && line[i + 1] == '|')
			i++;
		if (line[i] == '|')
		{
			i++;
			while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
					i++;
			if (!line[i] || line[i] == '|')
			{
				ft_putstr_fd("minishell: parse error\n", 2);
				set_env_val("?", "1", g_envp);
				return (true);
			}
		}
	}
	return (false);
}

t_bool	validate_line(char *line, char **lastline)
{
	(void)lastline;
	if (is_blank_line(line))
		return (false);
	if (is_incorrect_redirection(line))
		return (false);
	if (is_odd_quotes(line))
		return (false);
	if (is_file_invalid(line))
		return (false);
	if (is_empty_pipes(line))
		return (false);
	return (true);
}
