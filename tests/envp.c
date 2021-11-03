/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:15:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/02 21:57:11 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//note how accessing and modifiying the global variable does not impact valgrind
static void testoutofscope()
{
	__environ[500] = "MUCH=wow";
	__environ[501] = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	// i = 0;
	// while (envp[i])
	// 	ftex_minprintf("%s\n", envp[i++]);
	i = 0;
	testoutofscope();
	__environ[502] = "VERY=nice";
	while (__environ[i])
		ftex_minprintf("%s\n", __environ[i++]);
	ftex_minprintf("null environ index: %d\n", i);
	ftex_minprintf("%s\n", __environ[500]);
	ftex_minprintf("%s\n", __environ[502]);
	return (0);
}
