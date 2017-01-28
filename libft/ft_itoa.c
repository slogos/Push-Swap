/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:56:26 by slogos            #+#    #+#             */
/*   Updated: 2016/11/12 16:56:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*except(int n, char *nb)
{
	if (n < -2147483647)
	{
		ft_memset(nb, '\0', ft_strlen("-2147483648") + 1);
		ft_memmove(nb, "-2147483648", 11);
	}
	else
	{
		ft_memset(nb, '\0', ft_strlen("0") + 1);
		ft_memmove(nb, "0", 2);
	}
	return (nb);
}

char		*ft_itoa(int n)
{
	char	*nb;
	int		i;
	int		j;
	int		len;
	int		sign;

	i = 0;
	len = ft_nbrlen(n);
	sign = n < 0 ? -1 : 1;
	n < 0 ? n = -n : 0;
	n < 0 ? len++ : 0;
	j = (sign < 0) ? len + 1 : len;
	nb = ft_strnew(len + 2);
	if (n < -2147483647 || n == 0)
		return (except(n, nb));
	nb[j--] = '\0';
	while (i < len)
	{
		nb[j--] = n % 10 + '0';
		n /= 10;
		i++;
	}
	(sign == -1) ? nb[j] = '-' : 0;
	return (nb);
}
