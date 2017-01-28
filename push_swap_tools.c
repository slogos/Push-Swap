/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 01:36:38 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:07:29 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_print_out(t_list **list_a, t_list **list_b)
{
	t_list *swap_a;
	t_list *swap_b;

	swap_a = *list_a;
	swap_b = *list_b;
	ft_printf("\n\e[38;5;21;1;4ma stack\e[0m\n");
	while (swap_a)
	{
		ft_printf("%ld ", swap_a->n);
		swap_a = swap_a->next;
	}
	ft_printf("\n");
	ft_printf("\e[38;5;196;1;4mb stack\e[0m\n");
	while (swap_b)
	{
		ft_printf("%ld ", swap_b->n);
		swap_b = swap_b->next;
	}
	ft_printf("\n\n");
}

int		verify_order(t_list **list_a)
{
	t_list *swap;

	swap = *list_a;
	while (swap->next)
	{
		if (swap->n > swap->next->n)
			return (1);
		swap = swap->next;
	}
	return (0);
}

void	ft_brut_force(t_list **list_a, t_list **list_b)
{
	if (check_elements(&(*list_a)) == 2)
	{
		solve_two(&(*list_a));
		return ;
	}
	else if (check_elements(&(*list_a)) == 3)
	{
		solve_three(&(*list_a));
		return ;
	}
	else if (check_elements(&(*list_a)) == 4)
	{
		ft_pb((&*list_a), (&(*list_b)), 1);
		solve_three(&(*list_a));
		ft_find_b_position(&(*list_a), &(*list_b));
		return ;
	}
	else if (check_elements(&(*list_a)) == 5)
	{
		ft_pb((&*list_a), (&(*list_b)), 2);
		solve_three(&(*list_a));
		ft_find_b_position(&(*list_a), &(*list_b));
		ft_find_seconde_b_position(&(*list_a), &(*list_b));
		return ;
	}
}

void	solve_two(t_list **list_a)
{
	if ((*list_a)->n > (*list_a)->next->n)
		ft_sa(&(*list_a), 1);
}

void	ft_execute(char **s)
{
	if (!ft_strcmp(*s, "-v") || !ft_strcmp(*s, "-c"))
		return ;
	else
	{
		ft_printf("KO\n");
		exit(1);
	}
}
