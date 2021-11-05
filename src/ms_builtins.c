/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:45:49 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/05 02:38:25 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alt_echo(char *str)
{
	ftex_minprintf("%s", str);
}

void	alt_cd(char *str)
{
	ftex_minprintf("%s", str);
}

void	alt_pwd(char *str)
{
	ftex_minprintf("%s", str);
}
