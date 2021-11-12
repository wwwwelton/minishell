/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/12 03:43:30 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	too_many_arguments(char **str)
{
	if (str && str[1] && str[2])
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static char	*get_current_dir(void)
{
	int		buff_size;
	char	*cwd;

	buff_size = 128;
	cwd = NULL;
	while (cwd == NULL)
	{
		cwd = (char *)malloc(sizeof(char) * buff_size);
		if (getcwd(cwd, buff_size) == NULL)
		{
			ftex_null_ptr((void *)&cwd);
			buff_size += 128;
		}
	}
	ftex_null_ptr((void *)&cwd);
	cwd = (char *)malloc(sizeof(char) * ++buff_size);
	cwd[buff_size - 1] = '\0';
	if (getcwd(cwd, buff_size))
		return (cwd);
	return (NULL);
}

static void	update_env_dir(char *key, char *path, char **envp)
{
	char	*tmp;

	tmp = ft_strjoin(key, "=");
	tmp = ftex_strmerge(tmp, ft_strdup(path));
	set_env(key, tmp, envp);
	ftex_null_ptr((void *)&tmp);
}

int	alt_cd(char **str, char **envp)
{
	char	*old_dir;
	char	*cur_dir;

	if (too_many_arguments(str))
		return (EXIT_FAILURE);
	if (str && !str[1])
		return (EXIT_SUCCESS);
	old_dir = get_current_dir();
	if (chdir(str[1]))
	{
		ft_putstr_fd("cd: ", 1);
		perror(str[1]);
		ftex_null_ptr((void *)&old_dir);
		return (EXIT_FAILURE);
	}
	cur_dir = get_current_dir();
	if (ft_strncmp(old_dir, cur_dir, ft_strlen(old_dir)))
	{
		update_env_dir("OLDPWD", old_dir, envp);
		update_env_dir("PWD", cur_dir, envp);
	}
	ftex_null_ptr((void *)&old_dir);
	ftex_null_ptr((void *)&cur_dir);
	return (EXIT_SUCCESS);
}
