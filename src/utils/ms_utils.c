/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:37:37 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/13 03:18:15 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	envlen(char *str)
{
	int	i;

	i = 1;
	if (str[1] == '?')
		return (2);
	while (str[i])
	{
		if (ft_isalnum(str[i]))
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

t_bool	inside_here_doc(void)
{
	if (access(TMP_FILE, F_OK) == 0)
		return (true);
	return (false);
}
