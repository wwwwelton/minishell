/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:45:49 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/16 20:33:03 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//copy bash behaviour
int	alt_minishell(char **str, char **envp)
{
	str = envp;
	ftex_minprintf("%s", str[0]);
	return (0);
}
