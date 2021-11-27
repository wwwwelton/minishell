/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/11/27 01:52:33 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	printf_invalid_parameter(char *str)
{
	ft_putstr_fd("unset: `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

static int	is_alphanumeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isalnum(str[i]))
			return (0);
	return (1);
}

static void	unset_env(char *value, char **envp)
{
	int		i;
	char	**tmp;

	i = -1;
	while (envp[++i])
	{
		tmp = ft_split(envp[i], '=');
		if (!ft_strncmp(value, tmp[0], ft_strlen(value)))
		{
			free_splited_mat(tmp);
			break ;
		}
		free_splited_mat(tmp);
	}
	while (envp[i] && envp[i + 1])
	{
		ftex_null_ptr((void *)&envp[i]);
		envp[i] = ft_strdup(envp[i + 1]);
		i++;
	}
	envp[i] = NULL;
}

int	alt_unset(char **str, t_data *data)
{
	int	i;
	int	exit_code;

	if (str && !str[1])
		return (EXIT_SUCCESS);
	exit_code = 0;
	i = 0;
	while (str[++i])
	{
		if (!is_alphanumeric(str[i]))
		{
			printf_invalid_parameter(str[i]);
			exit_code = 1;
			continue ;
		}
		unset_env(str[i], data->alt_env);
	}
	return (exit_code);
}
