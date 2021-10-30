/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_str_replace_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:22:06 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/20 19:37:16 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief replaces all ocurrences of old in str with new
 *
 * @param str the old string, it needs to be heap allocated
 * @param old the pattern to be replaced
 * @param new the new pattern
 * @return char* the new freshly allocated string
 */
char	*ftex_str_replace_all(char *str, char *old, char *new)
{
	if (!str || !old || !new)
		return (NULL);
	while (ft_strnstr(str, old, ft_strlen(str)))
		str = ftex_str_replace(str, old, new);
	return (str);
}
