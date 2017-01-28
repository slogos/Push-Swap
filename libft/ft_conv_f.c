/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by slogos            #+#    #+#             */
/*   Updated: 2016/11/12 16:56:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putfloat(double nb, int preci, t_flags flag)
{
	long long		flt;
	long long		tmp;

	(!flag.display) ? ft_putnbr_ll((long)nb) : 0;
	flt = (nb - (long)nb) * ft_power(10, preci);
	if (nb > (long)nb && preci > 0)
	{
		(!flag.display) ? ft_putchar('.') : 0;
		tmp = (nb - (long)nb) * ft_power(10, preci + 1);
		if (tmp % 10 >= 5)
			flt += 1;
		(!flag.display) ? ft_putnbr_ll(flt) : 0;
	}
	else if (flag.hash)
		(!flag.display) ? ft_putchar('.') : 0;
	else if (flt == 0 && preci > 0)
	{
		(!flag.display) ? ft_putchar('.') : 0;
		while (preci--)
			(!flag.display) ? ft_putchar('0') : 0;
	}
}

static int		ft_f_helper(t_flags flag, double lpa, int sign, int space)
{
	int		prec;
	int		len;

	prec = (flag.preci <= 0) ? 1 : 0;
	len = ft_nbrlen_ll(lpa) + space + prec;
	ft_before_f(&flag, len + 6 + 1, lpa);
	(sign == 1 && (!flag.display)) ? ft_putchar('-') : 0;
	ft_putfloat(lpa, 6, flag);
	ft_after_f(&flag, len + 6 + 1 - prec + sign);
	return (len + 6 + 1 + flag.spaces_count + sign + space - prec);
}

int				ft_f(va_list pa, t_flags flag)
{
	double		lpa;
	int			space;
	int			len;
	int			sign;
	int			prec;

	lpa = va_arg(pa, double);
	(flag.empty == 1 && lpa > 0 && (!flag.display)) ? ft_putchar(' ') : 0;
	space = (flag.empty == 1) && (lpa > 0) ? 1 : 0;
	sign = (lpa < 0) ? 1 : 0;
	(sign == 1) ? lpa = -lpa : 0;
	prec = (flag.preci <= 0) ? 1 : 0;
	len = ft_nbrlen_ll(lpa) + space + prec;
	if (flag.preci == 0)
		return (ft_f_helper(flag, lpa, sign, space));
	ft_before_f(&flag, len + flag.preci + 1 - prec + sign, lpa);
	(sign == 1 && (!flag.display)) ? ft_putchar('-') : 0;
	ft_putfloat(lpa, flag.preci, flag);
	ft_after_f(&flag, len + flag.preci + 1 - prec + sign);
	return (len + flag.preci + 1 + flag.spaces_count + sign + space - prec);
}
