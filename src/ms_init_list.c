/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:30:54 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/27 01:53:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_names(void)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * 8);
	ret[0] = ft_strdup("echo");
	ret[1] = ft_strdup("cd");
	ret[2] = ft_strdup("pwd");
	ret[3] = ft_strdup("export");
	ret[4] = ft_strdup("unset");
	ret[5] = ft_strdup("env");
	ret[6] = ft_strdup("exit");
	ret[7] = NULL;
	return (ret);
}

void	fetch_list(t_builtin *node)
{
	int			i;
	char		**cmds;

	i = -1;
	cmds = init_names();
	while (cmds[++i])
	{
		node->name = ft_strdup(cmds[i]);
		if (cmds[i + 1])
		{
			node->next = (t_builtin *)malloc(sizeof(t_builtin));
			node = node->next;
		}
	}
	node->next = NULL;
	free_splited_mat(cmds);
}

void	init_builtins(t_builtin **head)
{
	t_builtin	*node;

	node = (t_builtin *)malloc(sizeof(t_builtin));
	*head = node;
	fetch_list(node);
	node->f = &alt_echo;
	node = node->next;
	node->f = &alt_cd;
	node = node->next;
	node->f = &alt_pwd;
	node = node->next;
	node->f = &alt_export;
	node = node->next;
	node->f = &alt_unset;
	node = node->next;
	node->f = &alt_env;
	node = node->next;
	node->f = &alt_exit;
}
