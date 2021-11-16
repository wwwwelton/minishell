/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser_presplit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:18:22 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/15 23:12:43 by jofelipe         ###   ########.fr       */
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

int	is_builtin(t_builtin *builtins, char *cmd)
{
	while (builtins)
	{
		if (!ft_strncmp(builtins->name, cmd, 64))
			return (1);
		builtins = builtins->next;
	}
	return (0);
}

void	identify_flags(t_flags *flags, t_builtin *builtins, char *cmd)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(cmd, ' ');
	if (is_builtin(builtins, tmp[0]))
		flags->builtins = 1;
	else
		flags->system_cmd = 1;
	while (tmp[++i])
	{
		if (tmp[i][0] == '<')
		{
			if (tmp[i][1] == '<')
				flags->heredoc = 1;
			else
				flags->file_in = ft_strdup(tmp[i + 1]);
		}
		if (tmp[i][0] == '>')
		{
			if (tmp[i][1] == '>')
				flags->out_append = 1;
			flags->file_out = ft_strdup(tmp[i + 1]);
		}
	}
	free_splited_mat(tmp);
}

void	clean_command(t_flags **flags, char **arr)
{
	int		i;
	char	*clean;
	char	*tmp;

	i = 0;
	while (arr[i])
	{
		if (flags[i]->file_in)
		{
			clean = ft_strnstr(arr[i], flags[i]->file_in, ft_strlen(arr[i]));
			ft_memset(clean, ' ', ft_strlen(flags[i]->file_in));
			tmp = arr[i];
			arr[i] = ftex_strerase(arr[i], "<>\\;");
			free(tmp);
		}
		if (flags[i]->file_out)
		{
			clean = ft_strnstr(arr[i], flags[i]->file_out, ft_strlen(arr[i]));
			ft_memset(clean, ' ', ft_strlen(flags[i]->file_out));
			tmp = arr[i];
			arr[i] = ftex_strerase(arr[i], "<>\\;");
			free(tmp);
		}
		i++;
	}
}

void	pre_split(t_data *data, char *line)
{
	int	i;

	i = -1;
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
	i = -1;
	// while (data->presplit[++i])
	// 	ftex_minprintf("%s\n", data->presplit[i]);
	clean_command(data->flags, data->presplit);
}
