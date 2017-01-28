/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbnr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by slogos            #+#    #+#             */
/*   Updated: 2016/11/12 16:56:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long nb, int base, int maj)
{
	char	*str;

	str = maj ? "0123456789ABCDEF" : "0123456789abcdef";
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < base)
		ft_putchar(str[nb]);
	else
	{
		ft_putnbr_base(nb / base, base, maj);
		ft_putnbr_base(nb % base, base, maj);
	}
}
