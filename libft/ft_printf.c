/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by slogos            #+#    #+#             */
/*   Updated: 2016/11/12 16:56:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		format_verify(const char *str, int i)
{
	while (str[i])
	{
		if (ft_is_printf(str[i]) == 1 || ft_is_printf(str[i]) == 2)
			return (1);
		i++;
	}
	return (0);
}

int				ft_is_printf(char c)
{
	if (c == '%' || c == 'd' || c == 'D' || c == 'i' || c == 'x' || c == 'X'
		|| c == 's' || c == 'S' || c == 'p' || c == 'c' || c == 'C' || c == 'o'
		|| c == 'O' || c == 'u' || c == 'U' || c == 'f' || c == 'F')
		return (1);
	if (c == '.' || ft_isnumber(c) || c == '#' || c == '-' || c == '+'
		|| c == ' ' || c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == '!'
		|| c == '*')
		return (0);
	return (2);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			value;

	i = -1;
	value = 0;
	va_start(ap, format);
	if (format == NULL)
		return (-1);
	while (format[++i])
	{
		(format[i] == '{') ? ft_color(format, &i) : 0;
		if (!format[i] || (format[i] == '%' && !format_verify(format, i + 1)))
			return (value);
		format[i] == '%' && format[i + 1] == '\0' ? value-- : 0;
		format[i] == '%' ? 0 : ft_putchar(format[i]);
		if (format[i] == '%' && format_verify(format, i + 1)
			&& (i = ft_printf_conv((char *)format, &ap, &value, i + 1)) == -1)
			return (-1);
		value++;
	}
	va_end(ap);
	return (value);
}
