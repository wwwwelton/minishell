/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:32:06 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/10 11:52:13 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data **data)
{
	t_data		*node;
	t_patterns	*patterns;
	t_builtin	*head;

	node = (t_data *)malloc(sizeof(t_data));
	init_patterns(&patterns);
	node->patterns = patterns;
	init_builtins(&head);
	node->head = head;
	*data = node;
}
