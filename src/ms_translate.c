/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:56:07 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/10 08:01:58 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_name_size(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(ft_isdigit(*str) || (*str >= 'A' && *str <= 'Z'))
		++i;
	return (i);
}

char	*find_quotes(char *str)
{
	char	*tmp;
	char	*envname;
	char	*envvalue;
	int		*envnamesize;

	if (!str)
		return (str);
	tmp = str;
	while (*tmp)
	{
		if (*tmp == 39)
			tmp += ft_strchr(tmp + 1, 39) - tmp + 1;
		if (*tmp == 34)
		{
			++tmp;
			while (*tmp != 34)
			{
				if (*tmp == '$')
				{
					env_name_size(++tmp)
				}
			}
			envname = ft_substr(tmp, 1, )
		}
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
