/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_translate_trim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:10:33 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/12 03:48:27 by jofelipe         ###   ########.fr       */
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
	size_t	i;
	int		size;
	char	*ret;
	char	*ptr;

	i = 0;
	ptr = str;
	if (!str)
		return (str);
	size = ft_strlen(str) - 2 + 1;
	ret = (char *)calloc(sizeof(char), size + 1);
	while (*str != quotes && *str)
		ret[i++] = *str++;
	if (*str == quotes)
		++str;
	while (*str != quotes && *str)
		ret[i++] = *str++;
	if (*str == quotes)
		++str;
	while (*str)
		ret[i++] = *str++;
	ret[i++] = '\0';
	free(ptr);
	return (ret);
}

static char	*find_quotes(char *str)
{
	size_t	i;
	int		size;

	i = -1;
	while (str[++i])
	{
		if (str[i] == DQUOTES)
		{
			size = quote_size(str, DQUOTES);
			str = remove_quotes(str, DQUOTES);
			i += size;
			if (i > ft_strlen(str))
				break ;
		}
		if (str[i] == SQUOTES)
		{
			size = quote_size(str, SQUOTES);
			str = remove_quotes(str, SQUOTES);
			i += size;
			if (i > ft_strlen(str))
				break ;
		}
	}
	return (str);
}

void	trim_quotes(char ***cmd)
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
	return ;
}
