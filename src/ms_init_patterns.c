/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_patterns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:14:26 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/10 11:36:24 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	null_patterns(t_patterns *patterns)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		patterns->backup[i] = NULL;
		patterns->holder[i] = NULL;
	}
}

void	init_patterns(t_patterns **patterns)
{
	t_patterns *node;
	node = (t_patterns *)malloc(sizeof(t_patterns));
	*patterns = node;
}
