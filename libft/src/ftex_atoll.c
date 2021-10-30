/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_atoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:17:25 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/05 19:31:07 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	validation(const char *str, int *ptrsign, int *ptri)
{
	long long	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*ptrsign *= -1;
		i++;
	}
	*ptri = i;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	return (1);
}

long long	ftex_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!validation(str, &sign, &i))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (result);
		else
			result = (result * 10) + (str[i] - '0') * sign;
		i++;
	}
	return (result);
}
