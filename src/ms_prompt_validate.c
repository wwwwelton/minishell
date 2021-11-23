/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:26:22 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/23 00:05:18 by jofelipe         ###   ########.fr       */
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
			ft_putstr_fd("zsh: parse error\n", 2);
			return (1);
		}
		break ;
	}
	return (0);
}

int	validate_line(char *line)
{
	if (is_blank_line(line))
		return (0);
	if (is_incorrect_redirection(line))
		return (0);
	return (1);
}
