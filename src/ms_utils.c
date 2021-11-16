/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:37:37 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/15 22:57:44 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	envlen(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || (str[i] >= 'A' && str[i] <= 'Z'))
			i++;
		else
			break ;
	}
	return (i);
}

int	len_to_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		++i;
	while (str[i] != ' ')
		++i;
	return (i);
}

void	print_matrix(char ***cmd)
{
	int	i;
	int	j;

	setbuf(stdout, NULL);
	i = -1;
	j = -1;
	while (cmd[++i])
	{
		ftex_minprintf("===== COMMAND %d ======\n\n", i + 1);
		while (cmd[i][++j])
			ftex_minprintf("%s|\n", cmd[i][j]);
		j = -1;
	}
}

void	debug(t_data *data)
{
	print_matrix(data->cmd);
}

void	free_splited_mat(char **mat)
{
	int	i;

	i = -1;
	if (mat)
	{
		while (mat[++i])
			ftex_null_ptr((void *)&mat[i]);
		ftex_null_ptr((void *)&mat);
	}
}

void	set_env(char *var, char *value, char **envp)
{
	int		i;
	char	**tmp;

	i = -1;
	while (envp[++i])
	{
		tmp = ft_split(envp[i], '=');
		if (!ft_strncmp(var, tmp[0], ft_strlen(var)))
		{
			ftex_null_ptr((void *)&envp[i]);
			envp[i] = ft_strdup(value);
			free_splited_mat(tmp);
			return ;
		}
		free_splited_mat(tmp);
	}
	envp[i] = ft_strdup(value);
	envp[i + 1] = NULL;
}

char	*get_env(char *value, char **envp)
{
	int		i;
	char	**tmp;

	if (!value || !*value)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		tmp = ft_split(envp[i], '=');
		if (!ft_strncmp(value, tmp[0], ft_strlen(value)))
		{
			free_splited_mat(tmp);
			return (ft_strdup(envp[i]));
		}
		free_splited_mat(tmp);
	}
	return (NULL);
}
