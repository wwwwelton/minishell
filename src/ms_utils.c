/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:28:09 by wleite            #+#    #+#             */
/*   Updated: 2021/11/08 16:49:11 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
