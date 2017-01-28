/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 23:33:46 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:11:32 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	swap_a(t_list **list_a)
{
	t_list *swap;

	if (*list_a && (*list_a)->next)
	{
		swap = *list_a;
		*list_a = (*list_a)->next;
		swap->next = (*list_a)->next;
		(*list_a)->next = swap;
	}
}

void	swap_b(t_list **list_b)
{
	t_list *swap;

	if (*list_b && (*list_b)->next)
	{
		swap = *list_b;
		*list_b = (*list_b)->next;
		swap->next = (*list_b)->next;
		(*list_b)->next = swap;
	}
}

void	swap_ss(t_list **list_a, t_list **list_b)
{
	swap_a(&(*list_a));
	swap_b(&(*list_b));
}

void	push_b(t_list **list_a, t_list **list_b)
{
	t_list *swap;

	if (*list_a)
	{
		swap = *list_b;
		*list_b = *list_a;
		*list_a = (*list_a)->next;
		(*list_b)->next = swap;
	}
}

void	push_a(t_list **list_a, t_list **list_b)
{
	t_list *swap;

	if (*list_b)
	{
		swap = *list_a;
		*list_a = *list_b;
		*list_b = (*list_b)->next;
		(*list_a)->next = swap;
	}
}
