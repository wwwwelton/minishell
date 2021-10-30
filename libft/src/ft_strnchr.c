/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:42:30 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/30 04:42:30 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *str, int len, int c)
{
	if (!str)
		return (NULL);
	while (len--)
	{
		if (*str == (char)c)
			return ((char *)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (NULL);
}
