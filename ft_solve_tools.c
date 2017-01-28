/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_four.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:38:33 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:04:52 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		ft_len(t_list **list)
{
	t_list	*swap;
	int		i;

	i = 0;
	swap = *list;
	while (swap)
	{
		i++;
		swap = swap->next;
	}
	return (i);
}

void	find_max_position(t_list **list_b, t_rot **list)
{
	t_list *swap_b;

	swap_b = *list_b;
	while (swap_b)
	{
		if (swap_b->n == (*list)->max)
			break ;
		(*list)->n++;
		swap_b = swap_b->next;
	}
}

void	find_min_position(t_list **list_b, t_rot **list)
{
	t_list *swap_b;

	swap_b = *list_b;
	while (swap_b)
	{
		if (swap_b->n == (*list)->min)
			break ;
		(*list)->n++;
		swap_b = swap_b->next;
	}
}

int		max_stack(t_list **list)
{
	t_list	*swap;
	int		max;

	swap = *list;
	max = swap->n;
	while (swap)
	{
		if (swap->n > max)
			max = swap->n;
		swap = swap->next;
	}
	return (max);
}

int		min_stack(t_list **list)
{
	t_list	*swap;
	int		max;

	swap = *list;
	max = swap->n;
	while (swap)
	{
		if (swap->n < max)
			max = swap->n;
		swap = swap->next;
	}
	return (max);
}
