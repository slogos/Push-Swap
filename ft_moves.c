/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:13:14 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:02:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_load_best(t_rot **swap, t_rot **best)
{
	(*best)->moves = (*swap)->moves;
	(*best)->ra = (*swap)->ra;
	(*best)->rb = (*swap)->rb;
	(*best)->rr = (*swap)->rr;
	(*best)->rra = (*swap)->rra;
	(*best)->rrb = (*swap)->rrb;
	(*best)->rrr = (*swap)->rrr;
}

void	ft_find_best(t_rot **list, t_rot **best)
{
	t_rot	*swap;
	int		i;

	i = 1;
	*best = NULL;
	ft_lstnew_move(&(*best));
	while (i)
	{
		swap = *list;
		while (swap)
		{
			if (swap->moves == i)
			{
				ft_load_best(&swap, &(*best));
				return ;
			}
			swap = swap->next;
		}
		i++;
	}
}

void	ft_load_moves_part_two(int *tab, t_rot **list)
{
	if ((*list)->moves == tab[2])
	{
		(*list)->rra = (*list)->len_a_diff;
		(*list)->rb = (*list)->n;
	}
	else if ((*list)->moves == tab[3] && (*list)->len_a_diff >= \
		(*list)->len_b_diff)
	{
		(*list)->rrr = (*list)->len_b_diff;
		(*list)->rra = (*list)->len_a_diff - (*list)->len_b_diff;
	}
	else if ((*list)->moves == tab[3] && (*list)->len_a_diff < \
		(*list)->len_b_diff)
	{
		(*list)->rrr = (*list)->len_a_diff;
		(*list)->rrb = (*list)->len_b_diff - (*list)->len_a_diff;
	}
}

void	ft_load_moves(int *tab, t_rot **list)
{
	if ((*list)->moves == tab[0] && (*list)->m >= (*list)->n)
	{
		(*list)->rr = (*list)->n;
		(*list)->ra = (*list)->m - (*list)->n;
	}
	else if ((*list)->moves == tab[0] && (*list)->m < (*list)->n)
	{
		(*list)->rr = (*list)->m;
		(*list)->rb = (*list)->n - (*list)->m;
	}
	else if ((*list)->moves == tab[1])
	{
		(*list)->ra = (*list)->m;
		(*list)->rrb = (*list)->len_b_diff;
	}
	else
		ft_load_moves_part_two(tab, &(*list));
}

void	ft_best_move(t_rot **list)
{
	int tab[4];

	(*list)->len_a_diff = (*list)->len_a - (*list)->m;
	(*list)->len_b_diff = (*list)->len_b - (*list)->n;
	if ((*list)->m >= (*list)->n)
		tab[0] = (*list)->m;
	else if ((*list)->m < (*list)->n)
		tab[0] = (*list)->n;
	tab[1] = (*list)->m + (*list)->len_b - (*list)->n;
	tab[2] = (*list)->len_a - (*list)->m + (*list)->n;
	if ((*list)->len_a_diff >= (*list)->len_b_diff)
		tab[3] = (*list)->len_a_diff;
	else if ((*list)->len_a_diff < (*list)->len_b_diff)
		tab[3] = (*list)->len_b_diff;
	(tab[0] <= tab[1] && tab[0] <= tab[2] && tab[0] <= tab[3]) ? \
		(*list)->moves = tab[0] : 0;
	(tab[1] <= tab[0] && tab[1] <= tab[2] && tab[1] <= tab[3]) ? \
		(*list)->moves = tab[1] : 0;
	(tab[2] <= tab[1] && tab[2] <= tab[0] && tab[2] <= tab[3]) ? \
		(*list)->moves = tab[0] : 0;
	(tab[3] <= tab[0] && tab[3] <= tab[2] && tab[3] <= tab[1]) ? \
		(*list)->moves = tab[3] : 0;
	ft_load_moves(tab, &(*list));
}
