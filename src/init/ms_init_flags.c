/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:53:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/11 01:53:23 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_flags(t_flags **flags, int cmds)
{
	int	i;

	i = 0;
	while (i < cmds)
	{
		flags[i]->builtins = 0;
		flags[i]->system_cmd = 0;
		flags[i]->error = 0;
		i++;
	}
	flags[i] = NULL;
}
