/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_translate_home.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 06:55:29 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/17 09:24:38 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_home(char *line, char *to_find)
{
	char	*home;

	home = get_env_val("HOME", g_envp);
	line = ftex_str_replace(line, to_find, home);
	free(home);
	return (line);
}
