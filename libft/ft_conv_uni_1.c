/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uni_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by slogos            #+#    #+#             */
/*   Updated: 2016/11/12 16:56:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The ft_put_preci_uni() function adjusts the precision before displaying
** the output.
*/

void	ft_put_preci_uni(t_flags *flags, long long local_pa)
{
	int		len;
	int		i;

	i = 0;
	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	while (flags->preci - len - flags->hash > 0)
	{
		(!flags->display) ? ft_putchar('0') : 0;
		flags->spaces_count++;
		flags->preci--;
		flags->preci_diff++;
	}
	if (local_pa == 0 && flags->preci != -1)
		(!flags->display) ? ft_putnbr_base_ull(local_pa, 10, 0) : 0;
	else if (local_pa != 0)
		(!flags->display) ? ft_putnbr_base_ull(local_pa, 10, 0) : 0;
}
