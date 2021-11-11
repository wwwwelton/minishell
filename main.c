/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:29:28 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/10 11:59:09 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_data		*data;

	g_environ = __environ;
	init_data(&data);
	// printfunctions(head);
	while (1)
		minishell(data);
	return (0);
}