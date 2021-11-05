/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:52:08 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/05 02:58:43 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alt_export(char *str)
{
	ftex_minprintf("%s", str);
}

void	alt_unset(char *str)
{
	ftex_minprintf("%s", str);
}

void	alt_env(char *str)
{
	ftex_minprintf("%s", str);
}

void	alt_exit(char *str)
{
	ftex_minprintf("%s", str);
}
