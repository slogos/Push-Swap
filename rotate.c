/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 23:37:19 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:08:41 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	rotate_ra(t_list **list_a)
{
	t_list *swap;
	t_list *begin;

	if (*list_a && (*list_a)->next)
	{
		swap = *list_a;
		begin = *list_a;
		*list_a = (*list_a)->next;
		while (begin->next)
			begin = begin->next;
		swap->next = NULL;
		begin->next = swap;
	}
}

void	rotate_rb(t_list **list_b)
{
	t_list *swap;
	t_list *begin;

	if (*list_b && (*list_b)->next)
	{
		swap = *list_b;
		begin = *list_b;
		*list_b = (*list_b)->next;
		while (begin->next)
			begin = begin->next;
		swap->next = NULL;
		begin->next = swap;
	}
}

void	rotate_rr(t_list **list_a, t_list **list_b)
{
	rotate_ra(&(*list_a));
	rotate_rb(&(*list_b));
}

void	ft_lstdel_all(t_list **list_a, t_rot **best)
{
	ft_lstdel_t(&(*list_a));
	ft_lstdel_m(&(*best));
}

void	ft_init_list(t_list **list_a, t_list **list_b)
{
	*list_a = NULL;
	*list_b = NULL;
	ft_lstnew(&(*list_a));
}
