/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:53:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/22 16:32:00 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_flags(t_flags **flags, int cmds)
{
	int	i;

	i = 0;
	while (i < cmds)
	{
		flags[i]->file_in = NULL;
		flags[i]->file_out = NULL;
		flags[i]->out_append = 0;
		flags[i]->heredoc = 0;
		flags[i]->builtins = 0;
		flags[i]->system_cmd = 0;
		flags[i]->error = 0;
		i++;
	}
	flags[i] = NULL;
}
