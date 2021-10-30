/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_uitoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 04:48:56 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/22 20:16:05 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	unsigned_setvariables(unsigned int nbr, int *sign, int *size_str)
{
	int	i;

	*size_str = 0;
	i = 0;
	if (nbr < 0)
	{
		i++;
		*sign *= -1;
		nbr *= -1;
	}
	if (nbr == 0)
		*size_str += 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	*size_str = *size_str + i;
}

static void	unsigned_putnbr(unsigned int nbr, char *res, int *sign)
{
	int	i;

	i = 0;
	if (nbr == 0)
		res[i++] = '0';
	while (nbr != 0)
	{
		res[i] = (nbr % 10) + 48;
		i++;
		nbr = nbr / 10;
	}
	if (*sign == -1)
		res[i++] = '-';
	res[i] = '\0';
}

static void	unsigned_reverse_string(char *tab)
{
	int	i;
	int	buffer;
	int	size_str;

	size_str = ft_strlen(tab);
	i = 0;
	while (i < size_str / 2)
	{
		buffer = tab[i];
		tab[i] = tab[size_str - i - 1];
		tab[size_str - i - 1] = buffer;
		i++;
	}
}

char	*ftex_uitoa(unsigned int nbr)
{
	int		size_str;
	int		sign;
	char	*res;

	sign = 1;
	unsigned_setvariables(nbr, &sign, &size_str);
	res = (char *)malloc(size_str + 1 * sizeof(char));
	if (!res)
		return (NULL);
	unsigned_putnbr(nbr, res, &sign);
	unsigned_reverse_string(res);
	return (res);
}
