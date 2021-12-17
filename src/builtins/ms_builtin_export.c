/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:26 by wleite            #+#    #+#             */
/*   Updated: 2021/12/17 17:31:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	printf_invalid_parameter(char *str)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

static int	is_alphanumeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isalnum(str[i]) && str[i] != ':')
			return (0);
	return (1);
}

int	alt_export(char **str, t_data *data)
{
	int		i;
	int		exit_code;
	char	**tmp;

	if (str && !str[1])
		return (alt_env(str, data));
	exit_code = 0;
	i = 0;
	while (str[++i])
	{
		if (!ft_strchr(str[i], '='))
			continue ;
		tmp = ft_split(str[i], '=');
		if (!is_alphanumeric(tmp[0]))
		{
			printf_invalid_parameter(tmp[0]);
			exit_code = 1;
			continue ;
		}
		set_env(tmp[0], str[i], data->alt_env);
		free_splited_mat(tmp);
	}
	return (exit_code);
}
