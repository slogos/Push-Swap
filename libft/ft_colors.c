/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by slogos            #+#    #+#             */
/*   Updated: 2016/11/12 16:56:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			chk(char str)
{
	if (ft_isdigit(str) || str == 'A')
		return (1);
	return (0);
}

static void	ft_print_all_colors(void)
{
	int		i;
	int		j;

	i = 30;
	j = 0;
	while (i <= 37)
	{
		ft_printf("%s%d%s%C: %d%s\t", "\e[", i, ";1;3m", i + 35, \
			i - 30, "\e[0m");
		i++;
	}
	ft_putstr("\n\n\n");
	i = 0;
	while (i <= 255)
	{
		ft_printf("%s%d%s%C: %d%s\t", "\e[38;5;", i, "1;3m", \
			(9650 + i), i, "\e[0m");
		if (!((j + 1) % 32))
			ft_putstr("\n\n");
		else if (!((j + 1) % 8))
			ft_putstr("\n");
		i++;
		j++;
	}
}

int			ft_color(const char *s, int *i)
{
	int		color;

	if ((chk(s[*i + 1]) && s[*i + 2] == '}') || (chk(s[*i + 1]) && \
		chk(s[*i + 2]) && s[*i + 3] == '}') || (chk(s[*i + 1]) && \
		chk(s[*i + 2]) && chk(s[*i + 3]) && s[*i + 4] == '}'))
	{
		color = ft_atoi(&s[*i + 1]);
		if (s[*i + 1] == 'A' && s[*i + 2] == '}')
			ft_print_all_colors();
		else if (color == 0)
			write(1, "\e[0m", 4);
		else
			ft_printf("\e[38;5;%dm", color);
		if (s[*i + 1] && s[*i + 2] == '}')
			*i += 3;
		else if (s[*i + 1] && s[*i + 2] && s[*i + 3] == '}')
			*i += 4;
		else if (s[*i + 1] && s[*i + 2] && s[*i + 3] && s[*i + 4] == '}')
			*i += 5;
		return (0);
	}
	return (1);
}
