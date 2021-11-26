/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:32:06 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/26 00:39:02 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_data *node)
{
	int		i;

	i = -1;
	while (++i < 200)
		node->alt_env[i] = NULL;
	i = -1;
	node->alt_env[++i] = ft_strdup("?=0");
	while (__environ[++i])
		node->alt_env[i] = ft_strdup(__environ[i]);
	g_envp = node->alt_env;
}

void	init_data(t_data **data)
{
	t_data		*node;
	t_pat		*pat;
	t_builtin	*head;

	unlink(TMP_FILE);
	node = (t_data *)malloc(sizeof(t_data));
	node->lastline = NULL;
	init_pat(&pat);
	node->pat = pat;
	init_builtins(&head);
	node->head = head;
	init_env(node);
	*data = node;
}
