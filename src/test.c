/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 01:44:41 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/22 03:46:38 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void scope(t_flags *flags)
{
	int i = 0;
	flags->redir_in[i++].file_in = ft_strdup("hello");
	flags->redir_in[i++].file_in = ft_strdup("my");
	flags->redir_in[i++].file_in = ft_strdup("dear");
	flags->redir_in[i++].file_in = ft_strdup("friend");
	flags->redir_in[i++].file_in = NULL;
}
int	main(void)
{
	t_flags *flags;
	int		i;

	i = -1;
	flags = malloc(sizeof(t_flags) * 1);
	scope(flags);
	while (flags->redir_in[++i].file_in)
		ftex_minprintf("%s\n", flags->redir_in[i].file_in);
}
