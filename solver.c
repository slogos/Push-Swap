/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:10:46 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:10:56 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	verify_position(t_list **list_a, t_list **list_b, t_rot **list)
{
	t_list	*swap_a;
	t_list	*swap_b;
	t_rot	*list_p;
	int		i;

	i = 0;
	(*list)->m = 0;
	swap_a = *list_a;
	list_p = *list;
	while (swap_a)
	{
		swap_b = *list_b;
		list_p->n = 0;
		while (swap_b)
		{
			if (ft_solver_min_max(&(*list_a), &(*list_b), &swap_a, &list_p))
				break ;
			else if (ft_solver_all(&swap_a, &swap_b, &list_p))
				break ;
			list_p->n++;
			swap_b = swap_b->next;
		}
		(swap_a->next != NULL) ? ft_next_list(&list_p, &i) : 0;
		swap_a = swap_a->next;
	}
}

int		ft_solver_min_max(t_list **list_a, t_list **list_b, \
			t_list **swap_a, t_rot **list_p)
{
	ft_load_zero(&(*list_a), &(*list_b), &(*list_p));
	if ((*swap_a)->n > (*list_p)->max)
	{
		find_max_position(&(*list_b), &(*list_p));
		ft_best_move(&(*list_p));
		return (1);
	}
	else if ((*swap_a)->n < (*list_p)->min)
	{
		find_min_position(&(*list_b), &(*list_p));
		ft_best_move(&(*list_p));
		(*list_p)->rb++;
		return (1);
	}
	return (0);
}

int		ft_solver_all(t_list **swap_a, t_list **swap_b, t_rot **list_p)
{
	if ((*swap_b)->next && (*swap_a)->n < (*swap_b)->n && \
		(*swap_a)->n > (*swap_b)->next->n)
	{
		(*list_p)->n++;
		ft_best_move(&(*list_p));
		return (1);
	}
	return (0);
}

void	ft_solve(t_list **list_a, t_list **list_b, t_rot **list, \
			t_rot **best)
{
	*list = NULL;
	ft_lstnew_move(&(*list));
	verify_position(&(*list_a), &(*list_b), &(*list));
	ft_find_best(&(*list), &(*best));
	ft_lstdel_m(&(*list));
	((*best)->rrr > 0) ? ft_rrr(&(*list_a), &(*list_b), (*best)->rrr) : 0;
	((*best)->rr > 0) ? ft_rr(&(*list_a), &(*list_b), (*best)->rr) : 0;
	((*best)->ra > 0) ? ft_ra(&(*list_a), (*best)->ra) : 0;
	((*best)->rb > 0) ? ft_rb(&(*list_b), (*best)->rb) : 0;
	((*best)->rra > 0) ? ft_rra(&(*list_a), (*best)->rra) : 0;
	((*best)->rrb > 0) ? ft_rrb(&(*list_b), (*best)->rrb) : 0;
	ft_pb(&(*list_a), &(*list_b), 1);
}

void	ft_solve_end(t_list **list_a, t_list **list_b, t_rot **best, int *i)
{
	(*best)->n = 0;
	(*best)->max = max_stack(&(*list_b));
	find_max_position(&(*list_b), &(*best));
	(*best)->len_b = ft_len(&(*list_b));
	(*best)->len_b_diff = (*best)->len_b - (*best)->n;
	((*best)->n <= (*best)->len_b / 2) ? ft_rb(&(*list_b), (*best)->n) : \
		ft_rrb(&(*list_b), (*best)->len_b_diff);
	ft_pa(&(*list_a), &(*list_b), *i);
}
