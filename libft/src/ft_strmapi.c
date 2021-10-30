/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:21:11 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/30 04:41:57 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = -1;
	if (!s || !f)
		return (NULL);
	res = ft_strdup((char *)s);
	if (!res)
		return (NULL);
	while (s[++i])
		res[i] = f(i, s[i]);
	return (res);
}
