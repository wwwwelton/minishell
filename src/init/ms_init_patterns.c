/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_pat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:14:26 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/10 11:36:24 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	null_pat(t_pat *pat)
{
	int	i;

	i = -1;
	pat->i = 0;
	while (++i < 50)
	{
		pat->backup[i] = NULL;
		pat->holder[i] = NULL;
	}
}

void	init_pat(t_pat **pat)
{
	t_pat	*node;

	node = (t_pat *)malloc(sizeof(t_pat));
	null_pat(node);
	*pat = node;
}
