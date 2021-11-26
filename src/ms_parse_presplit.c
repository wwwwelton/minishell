/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_presplit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:18:22 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/24 02:01:37 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipes(char *line)
{
	int	i;

	i = 1;
	if (!line)
		return (i);
	while (*line)
	{
		if (*line == '|')
			++i;
		++line;
	}
	return (i);
}

char	*clean_file_in(t_flags *flags, char *str)
{
	int		i;
	char	*clean;
	char	*tmp;

	i = -1;
	while (flags->redir_in[++i].file_in)
	{
		clean = ft_strnstr(str, flags->redir_in[i].file_in, ft_strlen(str));
		ft_memset(clean, ' ', ft_strlen(flags->redir_in[i].file_in));
		tmp = str;
		str = ftex_strerase(str, "<>\\;");
		free(tmp);
	}
	return (str);
}

char	*clean_file_out(t_flags *flags, char *str)
{
	int		i;
	char	*clean;
	char	*tmp;

	i = -1;
	while (flags->redir_out[++i].file_out)
	{
		clean = ft_strnstr(str, flags->redir_out[i].file_out, ft_strlen(str));
		ft_memset(clean, ' ', ft_strlen(flags->redir_out[i].file_out));
		tmp = str;
		str = ftex_strerase(str, "<>\\;");
		free(tmp);
	}
	return (str);
}

void	clean_command(t_flags **flags, char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		if (flags[i]->redir_in[0].file_in)
			arr[i] = clean_file_in(flags[i], arr[i]);
		if (flags[i]->redir_out[0].file_out)
			arr[i] = clean_file_out(flags[i], arr[i]);
	}
}

char	*pre_split(t_data *data, char *line)
{
	int		i;

	i = -1;
	line = find_stars(line);
	if (ft_strchr(line, '|'))
		data->presplit = ft_split(line, '|');
	else
	{
		data->presplit = (char **)malloc(sizeof(char *) * 2);
		data->presplit[0] = ft_strdup(line);
		data->presplit[1] = NULL;
	}
	while (data->presplit[++i])
		identify_flags(data->flags[i], data->head, data->presplit[i]);
	clean_command(data->flags, data->presplit);
	return (line);
}
