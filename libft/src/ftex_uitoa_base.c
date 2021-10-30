/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_uitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 04:46:19 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/22 10:29:59 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse_string(char *tab)
{
	int	counter;
	int	buffer;
	int	size;

	size = ft_strlen(tab);
	counter = 0;
	while (counter < size / 2)
	{
		buffer = tab[counter];
		tab[counter] = tab[size - counter - 1];
		tab[size - counter - 1] = buffer;
		counter++;
	}
}

static int	count_numbers(unsigned long nbr, int basesize)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr = nbr / basesize;
		i++;
	}
	return (i);
}

char	*ftex_uitoa_base(
	unsigned long nbr, char *base_to, unsigned long basesize)

{
	int		i;
	char	*res;
	int		size_str;

	size_str = count_numbers(nbr, basesize);
	res = (char *)malloc((size_str + 1) * sizeof(char));
	i = 0;
	if (nbr == 0)
		res[i++] = base_to[0];
	while (nbr)
	{
		res[i] = base_to[nbr % basesize];
		i++;
		nbr = nbr / basesize;
	}
	res[i] = '\0';
	ft_reverse_string(res);
	return (res);
}
