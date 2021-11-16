/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:56:07 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/15 22:35:59 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_single_quotes(t_pat *pat, char **cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		while (cmd[i][j])
		{
			if (cmd[i][j] == DQUOTES)
			{
				++j;
				while (cmd[i][j] != DQUOTES && cmd[i][j])
					++j;
			}
			if (cmd[i][j] == SQUOTES)
			{
				cmd[i] = single_quotes(pat, cmd[i], j);
				j = 0;
			}
			++j;
		}
		j = 0;
		++i;
	}
}

void	printcmd(char ***cmd)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cmd[++i])
	{
		while (cmd[i][++j])
			ftex_minprintf("%s\n", cmd[i][j]);
		j = -1;
	}
}

char	*replace_env(char *cmd)
{
	int		i;
	char	*env;
	char	*envvalue;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$')
		{
			env = ft_substr(cmd, i, envlen(&cmd[i]));
			envvalue = getenv(&env[1]);
			if (!envvalue)
				envvalue = ft_strdup("");
			if (DEBUG)
			{
				ftex_minprintf("env: %s\n", env);
				ftex_minprintf("evnvalue: %s\n", envvalue);
			}
			cmd = ftex_str_replace(cmd, env, envvalue);
			if (DEBUG)
				ftex_minprintf("cmd after env: %s\n", cmd);
			free(env);
			// free(envvalue);
		}
		i++;
	}
	return (cmd);
}

char	***find_env(char ***cmd)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (cmd[++i])
	{
		while (cmd[i][++j])
		{
			if (ft_strchr(cmd[i][j], '$'))
			{
				cmd[i][j] = replace_env(cmd[i][j]);
				j = -1;
			}
		}
		j = -1;
	}
	return (cmd);
}

char	***translate(t_pat *pat, char ***cmd, char **envp)
{
	int	i;

	i = -1;
	pat->i = 0;
	if (!pat->backup[0])
		return (cmd);
	while (cmd[++i])
	{
		replace_single_quotes(pat, cmd[i]);
	}
	cmd = find_env(cmd);
	// if (DEBUG)
	// {
	// 	ftex_minprintf("\n===== TRANSLATE ======\n");
	// 	printcmd(cmd);
	// 	ftex_minprintf("\n");
	// }
	cmd = restore_quoted(pat, cmd);
	cmd = trim_quotes(cmd);
	return (cmd);
}
