/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:23:41 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/23 01:23:30 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**parse_path(char **envp)
{
	int		i;
	char	**ret;

	i = 0;
	while (envp)
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			ret = ft_split(envp[i], ':');
			return (ret);
		}
		i++;
	}
	return (NULL);
}

static char	*test_access(char **path, char *cmd)
{
	int		i;
	char	*bin;
	char	*cmd2;

	i = 1;
	while (path[i])
	{
		cmd2 = ft_strjoin("/", cmd);
		bin = ft_strjoin(path[i++], cmd2);
		free(cmd2);
		if (!access(bin, X_OK))
			return (bin);
		else
			free(bin);
	}
	return (NULL);
}

static char
	**parse_access(char **path, char ***cmd, int cmd_count)
{
	int		i;
	char	**accesspath;

	accesspath = (char **)malloc((cmd_count + 1) * sizeof(char *));
	i = 0;
	while (cmd[i])
	{
		accesspath[i] = test_access(path, cmd[i][0]);
		if (!accesspath[i])
		{
			accesspath[i] = ft_strdup(cmd[i][0]);
			// cleanup(data, errno);
		}
		++i;
	}
	accesspath[i] = NULL;
	return (accesspath);
}

char	*empty_command_handler(char *str, int heredoc, char *filein)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (str);
	if (heredoc)
	{
		free (str);
		return (ft_strdup("cat"));
	}
	if (filein)
	{
		free (str);
		return (ft_strdup("less"));
	}
	free (str);
	return (ft_strdup(""));
}

void	parser(t_data *data, char *line)
{
	int		cmd_count;
	int		i;

	i = 0;
	data->path = parse_path(data->alt_env);
	line = replace_quoted(data->pat, line);
	cmd_count = count_pipes(line);
	data->flags = (t_flags **)malloc(sizeof(t_flags *) * (cmd_count + 1));
	while (i < cmd_count)
		data->flags[i++] = (t_flags *)malloc(sizeof(t_flags) * 1);
	data->flags[i] = NULL;
	init_flags(data->flags, cmd_count);
	line = pre_split(data, line);
	data->cmd = (char ***)malloc(sizeof(char *) * (cmd_count + 1));
	i = -1;
	while (data->presplit[++i])
	{
		data->presplit[i] = empty_command_handler(data->presplit[i],
				data->flags[i]->heredoc, data->flags[i]->file_in);
		data->cmd[i] = ft_split(data->presplit[i], ' ');
	}
	data->cmd[i] = NULL;
	data->cmd = restore_quoted(data->pat, data->cmd);
	data->accesspath = parse_access(data->path, data->cmd, cmd_count);
	free(line);
}
