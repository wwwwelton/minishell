/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:15:38 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/09 09:42:10 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//moral: environ is not updated by exec commands
int	main(int argc, char **argv, char **envp)
{
	int	pid;
	g_environ = __environ;

	ft_putstr_fd(getenv("USER"), 1);
	// pid = fork();
	execlp("unset", "unset", "USER");
	wait(NULL);
	ft_putstr_fd(getenv("USER"), 1);
}
