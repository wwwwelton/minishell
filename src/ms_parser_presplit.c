/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser_presplit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:18:22 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/22 16:52:26 by jofelipe         ###   ########.fr       */
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

// void	clean_file_in(t_flags *flags, char *str)
// {
// 	int	i;

// 	i = -1;
// 	while (flags->redir_in[++i].file_in)
// 	{
// 		clean = ft_strnstr(arr[i], flags[i]->file_in, ft_strlen(arr[i]));
// 	}
// }

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
	clean_command(data->flags, data->presplit);
}
