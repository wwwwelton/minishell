/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:26:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/20 16:39:46 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_to_next(char *str, char to_find)
{
	int	i;

	i = 1;
	while (str[i] != to_find)
		i++;
	return (i);
}

int	command_size(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == SQUOTES)
			i += len_to_next(&buf[i], SQUOTES);
		if (buf[i] == DQUOTES)
			i += len_to_next(&buf[i], DQUOTES);
		if (buf[i] != '|' && buf[i] != '&')
			continue ;
		if (buf[i + 1] == '|')
			return (i);
		if (buf[i + 1] == '&')
			return (i);
	}
	return (i);
}

t_bool	is_multiple_commands(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '|' && line[i] != '&')
			continue ;
		if (line[i + 1] == '|')
			return (true);
		if (line[i + 1] == '&')
			return (true);
	}
	return (false);
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

char	*fetch_buffer(t_data *data, char *buf, char *line, char **lastline)
{
	int		cmd_size;
	int		str_size;
	char	*ret;
	char	*last_return;

	last_return = get_env_val("?", g_envp);
	while (buf[0] == '|' && last_return[0] == '0')
		skip_command(buf);
	ftex_null_ptr((void *)&last_return);
	if (!*buf)
		return (prompt_loop(data, line, lastline));
	ft_memset(buf, ' ', 2);
	str_size = ft_strlen(buf);
	cmd_size = command_size(buf);
	ret = (char *)malloc(sizeof(char) * (cmd_size + 1));
	ft_strlcpy(ret, buf, cmd_size + 1);
	ft_memmove(buf, &buf[cmd_size], str_size - cmd_size);
	buf[str_size - cmd_size] = '\0';
	ret = token_echo(data->pat, ret);
	return (ret);
}
