/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:32:06 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/26 02:26:55 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	append_minishell_path(void)
{
	char	*shell;
	char	*path;
	char	*slash;

	shell = get_env_val("_", g_envp);
	slash = ft_strrchr(shell, '/');
	ft_memset(slash, '\0', ft_strlen(slash));
	shell = ftex_str_replace(shell, "/.", "");
	shell = ftex_strmerge(ft_strdup(":"), shell);
	path = get_env_val("PATH", g_envp);
	path = ftex_strmerge(path, shell);
	set_env_val("PATH", path, g_envp);
	ftex_null_ptr((void *)&path);
}

void	init_env(t_data *node)
{
	int		i;

	i = -1;
	while (++i < 200)
		node->alt_env[i] = NULL;
	i = -1;
	node->alt_env[++i] = ft_strdup("?=0");
	while (g_envp[++i])
		node->alt_env[i] = ft_strdup(g_envp[i]);
	g_envp = node->alt_env;
	append_minishell_path();
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
