/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by slogos            #+#    #+#             */
/*   Updated: 2016/11/12 16:56:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_convert_base(long long n, int base, char *s, int *index)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (n < base)
	{
		s[*index] = str[n];
		*index += 1;
	}
	else
	{
		ft_convert_base(n / base, base, s, index);
		ft_convert_base(n % base, base, s, index);
	}
}

char				*ft_itoa_base(long long n, int base)
{
	char	*s;
	int		len;
	int		sign;

	len = ft_nbrlen_base(n, base);
	sign = n < 0 ? 1 : 0;
	n = sign == 1 ? -n : n;
	s = ft_strnew(len);
	sign ? s[0] = '-' : 0;
	ft_convert_base(n, base, s, &sign);
	return (s);
}
