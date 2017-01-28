/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 00:50:44 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:06:43 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	console(t_list **list_a, t_list **list_b, int *i)
{
	t_rot	*list;
	t_rot	*best;
	int		n;

	n = *i - 3;
	if (!verify_order(&(*list_a)))
		exit(1);
	if (check_elements(&(*list_a)) > 1 && check_elements(&(*list_a)) < 6)
	{
		ft_brut_force(&(*list_a), &(*list_b));
		exit(1);
	}
	ft_start_three(&(*list_a), &(*list_b));
	while (n)
	{
		ft_solve(&(*list_a), &(*list_b), &list, &best);
		n--;
	}
	ft_solve_end(&(*list_a), &(*list_b), &best, i);
	ft_lstdel_all(&(*list_a), &best);
}

int		main(int ac, char **av)
{
	int		i;
	char	*str;
	t_list	*list_a;
	t_list	*list_b;

	if (av[1] == NULL)
		return (0);
	ft_init_list(&list_a, &list_b);
	str = ft_strdup(av[1]);
	(check_digit(str) && check_minus_zero(str) && \
		ac == 2 && check_int_size(str, &list_a, &i)) && \
		check_match(&list_a) ? \
		console(&list_a, &list_b, &i) : ft_end(&list_a, str);
	return (0);
}
