/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:26:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/23 22:38:43 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_size(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] != '|' && buf[i] != '&')
			continue ;
		if (buf[i + 1] == '|')
			return (i);
		if (buf[i + 1] == '&')
			return (i);
	}
	return (i);
}

int	is_multiple_commands(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '|' && line[i] != '&')
			continue ;
		if (line[i + 1] == '|')
			return (i);
		if (line[i + 1] == '&')
			return (i);
	}
	return (0);
}

void	skip_command(char *buf)
{
	int	cmd_size;
	int	str_size;

	ft_memset(buf, ' ', 2);
	cmd_size = command_size(buf);
	str_size = ft_strlen(buf);
	ft_memmove(buf, &buf[cmd_size], str_size - cmd_size);
	buf[str_size - cmd_size] = '\0';
}

char	*fetch_buffer(char *buf, char *line, char **lastline, char **envp)
{
	int		cmd_size;
	int		str_size;
	char	*ret;

	while (buf[0] == '|' && !last_status_code(envp))
		skip_command(buf);
	if (!*buf)
		return (prompt_loop(line, lastline));
	ft_memset(buf, ' ', 2);
	str_size = ft_strlen(buf);
	cmd_size = command_size(buf);
	ret = (char *)malloc(sizeof(char) * (cmd_size + 1));
	ft_strlcpy(ret, buf, cmd_size + 1);
	ft_memmove(buf, &buf[cmd_size], str_size - cmd_size);
	buf[str_size - cmd_size] = '\0';
	return (ret);
}
