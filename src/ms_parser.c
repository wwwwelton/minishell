/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:23:41 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/10 18:12:57 by jofelipe         ###   ########.fr       */
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

	cmd_count = 1; //sep by pipes later
	data->cmd = malloc(sizeof(char *) * 2);
	data->path = parse_path(g_environ);

	line = replace_quoted(data->patterns, line);
	// ftex_minprintf("%s\n", line);
	data->cmd[0] = ft_split(line, ' '); //develop parser later
	data->cmd[1] = NULL;
	data->accesspath = parse_access(data, data->path, data->cmd, cmd_count);
	// ftex_minprintf("%s\n", data->path[1]);
	// ftex_minprintf("%s\n", data->cmd[0][0]);
	// ftex_minprintf("%s\n", data->cmd[0][1]);
}
