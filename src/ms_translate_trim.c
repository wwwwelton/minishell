/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_translate_trim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:10:33 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/17 01:51:07 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	quote_size(char *str, char find)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[++i] != find)
		++ret;
	return (ret);
}

static char	*remove_quotes(char *str, char quotes)
{
	int		i;
	int		size;
	char	*ret;

	i = 0;
	if (!str)
		return (str);
	size = ft_strlen(str) - 2 + 1;
	ret = (char *)malloc(sizeof(char) * size);
	while (*str != quotes)
		ret[i++] = *str++;
	++str;
	while (*str != quotes)
		ret[i++] = *str++;
	++str;
	while (*str)
		ret[i++] = *str;
	ret[i] = '\0';
	return (ret);
}

static char	*find_quotes(char *str)
{
	int		i;
	int		size;
	char	*pat;

	i = -1;
	if (!str)
		return (str);
	while (str[++i])
	{
		if (str[i] == DQUOTES)
		{
			size = quote_size(str, DQUOTES);
			str = remove_quotes(str, DQUOTES);
			i += size - 1;
		}
		if (str[i] == SQUOTES)
		{
			size = quote_size(str, SQUOTES);
			str = remove_quotes(str, SQUOTES);
			i += size - 1;
		}
	}
	return (str);
}

char	***trim_quotes(char ***cmd)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cmd[++i])
	{
		while (cmd[i][++j])
			cmd[i][j] = find_quotes(cmd[i][j]);
		j = -1;
	}
	return (cmd);
}
