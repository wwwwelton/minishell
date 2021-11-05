/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:30:54 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/05 03:05:09 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printfunctions(t_builtin *head)
{
	while (head)
	{
		ftex_minprintf("%s", head->name);
		head->f(head->name);
		head = head->next;
	}
}

void	fetch_list(t_builtin *node)
{
	int			fd;
	char		*line;


	fd = open("./builtins", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		node->name = line;
		line = get_next_line(fd);
		if (line)
		{
			node->next = (t_builtin *)malloc(sizeof(t_builtin));
			node = node->next;
		}
	}
	node->next = NULL;
	close(fd);
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
