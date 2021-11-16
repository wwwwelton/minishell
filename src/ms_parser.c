/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:23:41 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/16 12:53:54 by jofelipe         ###   ########.fr       */
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
			// ftex_minprintf("%s\n", envp[i]);
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
	return (ft_strdup(""));
}

static char
	**parse_access(t_data *data, char **path, char ***cmd, int cmd_count)
{
	int		i;
	char	**accesspath;

	accesspath = (char **)malloc((cmd_count + 1) * sizeof(char *));
	i = 0;
	while (cmd[i])
	{
		accesspath[i] = test_access(path, cmd[i][0]);
		if (!accesspath[i][0])
		{
			accesspath[++i] = NULL;
			data->accesspath = accesspath;
			// cleanup(data, errno);
		}
		++i;
	}
	accesspath[i] = NULL;
	return (accesspath);
}

void	parser(t_data *data, char *line)
{
	int		cmd_count;
	int		i;

	i = 0;
	data->path = parse_path(g_environ);
	line = replace_quoted(data->pat, line);
	cmd_count = count_pipes(line);
	data->flags = (t_flags **)malloc(sizeof(t_flags *) * cmd_count + 1);
	while (i < cmd_count)
		data->flags[i++] = (t_flags *)malloc(sizeof(t_flags));
	data->flags[i] = NULL;
	init_flags(data->flags, cmd_count);
	pre_split(data, line);
	data->cmd = (char ***)malloc(sizeof(char *) * cmd_count + 1);
	// ftex_minprintf("line after replace: %s\n", line);
	i = -1;
	while (data->presplit[++i])
		data->cmd[i] = ft_split(data->presplit[i], ' ');
	data->cmd[i] = NULL;
	data->cmd = restore_quoted(data->pat, data->cmd);
	data->accesspath = parse_access(data, data->path, data->cmd, cmd_count);
}
