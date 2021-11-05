/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:30:54 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/05 00:15:14 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo(char *str)
{
	ftex_minprintf("%s\n", str);
}

static void	ls(char *str)
{
	ftex_minprintf("%s\n", str);
}

void	printfunctions(t_builtin *head)
{
	while (head)
	{
		ftex_minprintf("%s\n", head->name);
		head->f(head->name);
		head = head->next;
	}
}

void	launch(t_builtin **head)
{
	t_builtin	*node;

	node = (t_builtin *)malloc(sizeof(t_builtin));
	node->name = ft_strdup("echo");
	node->f = &echo;
	*head = node;
	node->next = (t_builtin *)malloc(sizeof(t_builtin));
	node = node->next;
	node->name = ft_strdup("ls");
	node->f = &ls;
	node->next = NULL;
}
