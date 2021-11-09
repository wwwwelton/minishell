/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:56:07 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/09 10:07:15 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**replace_env()
{

}

char	*find_quotes(char *str)
{
	char *tmp;

	if (!str)
		return (str);
	tmp = str;
	while (*tmp)
	{
		if (*tmp == 39)
			tmp += ft_strchr(tmp + 1, 39) - tmp + 1;
		if (*tmp == 34)
			handle_double_quotes();
	}
}

void	translate(char ***cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i][j])
	{
		cmd[i][j] = find_quotes(cmd[i][j])
	}

}
