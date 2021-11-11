/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:32:06 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/11 15:37:02 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_data *node)
{
	int	i;

	i = -1;
	while (++i < 200)
		node->alt_env[i] = NULL;
	i = -1;
	while(__environ[++i])
		node->alt_env[i] = __environ[i];
}

void	init_data(t_data **data)
{
	t_data		*node;
	t_pat		*pat;
	t_builtin	*head;

	node = (t_data *)malloc(sizeof(t_data));
	init_pat(&pat);
	node->pat = pat;
	init_builtins(&head);
	node->head = head;
	init_env(node);
	*data = node;
}
