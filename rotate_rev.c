/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 23:39:07 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:09:38 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	rotate_rra(t_list **list_a)
{
	t_list *swap;
	t_list *begin;

	if (*list_a && (*list_a)->next)
	{
		swap = *list_a;
		begin = *list_a;
		while (begin->next->next)
			begin = begin->next;
		swap = begin->next;
		begin->next = NULL;
		swap->next = (*list_a);
		(*list_a) = swap;
	}
}

void	rotate_rrb(t_list **list_b)
{
	t_list *swap;
	t_list *begin;

	if (*list_b && (*list_b)->next)
	{
		swap = *list_b;
		begin = *list_b;
		while (begin->next->next)
			begin = begin->next;
		swap = begin->next;
		begin->next = NULL;
		swap->next = (*list_b);
		(*list_b) = swap;
	}
}

void	rotate_rrr(t_list **list_a, t_list **list_b)
{
	rotate_rra(&(*list_a));
	rotate_rrb(&(*list_b));
}

void	ft_load_zero(t_list **list_a, t_list **list_b, t_rot **list_p)
{
	(*list_p)->max = max_stack(&(*list_b));
	(*list_p)->min = min_stack(&(*list_b));
	(*list_p)->len_a = ft_len(&(*list_a));
	(*list_p)->len_b = ft_len(&(*list_b));
	(*list_p)->ra = 0;
	(*list_p)->rb = 0;
	(*list_p)->rr = 0;
	(*list_p)->rra = 0;
	(*list_p)->rrb = 0;
	(*list_p)->rrr = 0;
	(*list_p)->moves = 0;
}

void	ft_next_list(t_rot **list_p, int *i)
{
	ft_lstnew_move(&(*list_p));
	*list_p = (*list_p)->next;
	(*i)++;
	(*list_p)->m = *i;
}
