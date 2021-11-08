/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:06:25 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/08 00:33:32 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*prompt(void)
{
	char	*line;
	char	*cwd;
	char	*tmp;
	int		cwdsize;

	line = NULL;
	cwdsize = 100;
	cwd = (char *)ft_calloc(sizeof(char), cwdsize);
	cwd = getcwd(cwd, cwdsize);
	cwd = ftex_strmerge(cwd, ft_strdup("$"));
	while (!line)
	{
		ftex_minprintf("%s", cwd);
		line = readline(line);
		if (!*line)
		{
			ftex_minprintf("%s", cwd);
			ftex_null_ptr((void **)&line);
		}
	}
	free(cwd);
	tmp = line;
	line = ft_strtrim(line, " ");
	free(tmp);
	add_history(line);
	free(line);
	return (line);
}

int	main(void)
{
	prompt();
}
