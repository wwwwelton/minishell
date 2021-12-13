/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 02:48:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/12 00:59:55 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_dir_name(char **cwd)
{
	char	*dir_name;

	if (ft_strncmp(*cwd, "/", 2) == 0)
		return ;
	dir_name = ft_strrchr(*cwd, '/');
	dir_name = ft_substr(dir_name, 1, ft_strlen(dir_name));
	free(*cwd);
	*cwd = dir_name;
}

void	replace_cwd_path(char **cwd)
{
	char	*home;
	char	*pwd;

	home = get_env_val("HOME", g_envp);
	pwd = get_env_val("PWD", g_envp);
	if (!home || !pwd)
	{
		ftex_null_ptr((void *)&home);
		ftex_null_ptr((void *)&pwd);
		return ;
	}
	replace_dir_name(cwd);
	if (ft_strncmp(home, pwd, ft_strlen(home) + 1) == 0)
	{
		ftex_null_ptr((void *)&*cwd);
		*cwd = ft_strdup("~ ");
	}
	ftex_null_ptr((void *)&home);
	ftex_null_ptr((void *)&pwd);
}

void	paint_cwd(char **cwd)
{
	char	*success;

	replace_cwd_path(cwd);
	success = get_env_val("?", g_envp);
	if (*success == '0')
	{
		*cwd = ftex_strmerge(ft_strdup(BOLDBLUE), *cwd);
		*cwd = ftex_strmerge(*cwd, ft_strdup(RESET));
		*cwd = ftex_strmerge(ft_strdup(BOLDGREEN "➜  "), *cwd);
		*cwd = ftex_strmerge(*cwd, ft_strdup(RESET));
	}
	else
	{
		*cwd = ftex_strmerge(ft_strdup(BOLDBLUE), *cwd);
		*cwd = ftex_strmerge(*cwd, ft_strdup(RESET));
		*cwd = ftex_strmerge(ft_strdup(BOLDRED "➜  "), *cwd);
		*cwd = ftex_strmerge(*cwd, ft_strdup(RESET));
	}
	ftex_null_ptr((void *)&success);
}
