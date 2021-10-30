/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftex_minprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 08:22:04 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/23 10:00:26 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*apply_width(char *str, int len, int minus)
{
	char	*spaces;

	spaces = (char *)malloc(sizeof(char) * len + 1);
	spaces[len] = '\0';
	while (len--)
		spaces[len] = ' ';
	if (minus)
	{
		str = ftex_strmerge(str, spaces);
		free(spaces);
		return (str);
	}
	else
	{
		spaces = ftex_strmerge(spaces, str);
		free(str);
		return (spaces);
	}
}

char	format_parser(const char *s, t_pf *data)
{
	int	i;

	i = 1;
	data->width = 0;
	data->minus = 0;
	while (s[i] && s[i] != 's' && s[i] != 'p' && s[i] != 'd')
	{
		if (ft_isdigit(s[i]))
			data->width += data->width * 10 + (s[i] - '0');
		if (s[i] == '-')
			data->minus = 1;
		i++;
	}
	return (i + 1);
}

int	write_filler(const char *s, t_pf *data)
{
	int	i;

	i = 0;
	while (s[i] != '%' && s[i])
		++i;
	write(1, s, i);
	data->len += i;
	return (i);
}

void	call_conversion(t_pf *data, va_list args, char type)
{
	char	*str;

	if (type == 's')
		str = ft_strdup(va_arg(args, char *));
	if (type == 'p')
		str = ftex_uitoa_base(\
		(size_t)va_arg(args, void *), "0123456789abcdef", 16);
	if (type == 'd')
		str = ft_itoa(va_arg(args, int));
	data->len = ft_strlen(str);
	if (data->width - data->len > 0)
		str = apply_width(str, data->width - data->len, data->minus);
	ft_putstr_fd(str, 1);
	free(str);
}

void	ftex_minprintf(const char *s, ...)
{
	va_list	args;
	t_pf	data;

	va_start(args, s);
	while (ft_strnstr(s, "%", ft_strlen(s)))
	{
		s += write_filler(s, &data);
		s += format_parser(s, &data);
		call_conversion(&data, args, *(s - 1));
	}
	s += write_filler(s, &data);
	va_end(args);
}
