/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:07:58 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:00:01 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	solve_three(t_list **list_a)
{
	if (((*list_a)->n > (*list_a)->next->n) && \
		((*list_a)->next->n > (*list_a)->next->next->n))
		ft_solve_three_one(&(*list_a));
	else if (((*list_a)->n > (*list_a)->next->n) && \
		((*list_a)->next->n < (*list_a)->next->next->n && \
		(*list_a)->n > (*list_a)->next->next->n))
		ft_ra(&(*list_a), 1);
	else if (((*list_a)->n > (*list_a)->next->n) && \
		((*list_a)->next->n < (*list_a)->next->next->n && \
		(*list_a)->n < (*list_a)->next->next->n))
		ft_sa(&(*list_a), 1);
	else if (((*list_a)->n < (*list_a)->next->n) && \
		((*list_a)->next->n > (*list_a)->next->next->n && \
		(*list_a)->n > (*list_a)->next->next->n))
		ft_rra(&(*list_a), 1);
	else if (((*list_a)->n < (*list_a)->next->n) && \
		((*list_a)->next->n > (*list_a)->next->next->n && \
		(*list_a)->n < (*list_a)->next->next->n))
		ft_solve_three_five(&(*list_a));
}

void	solve_three_rev(t_list **list_b)
{
	if (((*list_b)->n > (*list_b)->next->n) && \
		((*list_b)->next->n < (*list_b)->next->next->n) && \
		((*list_b)->n > (*list_b)->next->next->n))
		ft_solve_three_one_rev(&(*list_b));
	else if (((*list_b)->n < (*list_b)->next->n) && \
		((*list_b)->next->n > (*list_b)->next->next->n && \
		(*list_b)->n > (*list_b)->next->next->n))
		ft_sb(&(*list_b), 1);
	else if (((*list_b)->n > (*list_b)->next->n) && \
		((*list_b)->next->n < (*list_b)->next->next->n && \
		(*list_b)->n < (*list_b)->next->next->n))
		ft_rrb(&(*list_b), 1);
	else if (((*list_b)->n < (*list_b)->next->n) && \
		((*list_b)->next->n < (*list_b)->next->next->n && \
		(*list_b)->n < (*list_b)->next->next->n))
		ft_solve_three_four_rev(&(*list_b));
	else if (((*list_b)->n < (*list_b)->next->n) && \
		((*list_b)->next->n > (*list_b)->next->next->n && \
		(*list_b)->n < (*list_b)->next->next->n))
		ft_rb(&(*list_b), 1);
}

void	ft_find_b_position(t_list **list_a, t_list **list_b)
{
	if ((*list_b)->n < (*list_a)->n)
		ft_pa(&(*list_a), &(*list_b), 1);
	else if ((*list_b)->n > (*list_a)->next->next->n)
	{
		ft_pa(&(*list_a), &(*list_b), 1);
		ft_ra(&(*list_a), 1);
	}
	else if ((*list_b)->n > (*list_a)->n && (*list_b)->n < (*list_a)->next->n)
	{
		ft_ra(&(*list_a), 1);
		ft_pa(&(*list_a), &(*list_b), 1);
		ft_rra(&(*list_a), 1);
	}
	else if ((*list_b)->n > (*list_a)->next->n && \
		(*list_b)->n < (*list_a)->next->next->n)
	{
		ft_rra(&(*list_a), 1);
		ft_pa(&(*list_a), &(*list_b), 1);
		ft_ra(&(*list_a), 2);
	}
}

void	ft_find_seconde_b_position(t_list **list_a, t_list **list_b)
{
	if ((*list_b)->n < (*list_a)->n)
		ft_pa(&(*list_a), &(*list_b), 1);
	else if ((*list_b)->n > (*list_a)->n && (*list_b)->n < (*list_a)->next->n)
	{
		ft_ra(&(*list_a), 1);
		ft_pa(&(*list_a), &(*list_b), 1);
		ft_rra(&(*list_a), 1);
	}
	else if ((*list_b)->n > (*list_a)->next->n && \
		(*list_b)->n < (*list_a)->next->next->n)
	{
		ft_ra(&(*list_a), 2);
		ft_pa(&(*list_a), &(*list_b), 1);
		ft_rra(&(*list_a), 2);
	}
	else
		ft_find_seconde_b_position_part_two(&(*list_a), &(*list_b));
}

void	ft_find_seconde_b_position_part_two(t_list **list_a, t_list **list_b)
{
	if ((*list_b)->n > (*list_a)->next->next->n && \
		(*list_b)->n < (*list_a)->next->next->next->n)
	{
		ft_rra(&(*list_a), 1);
		ft_pa(&(*list_a), &(*list_b), 1);
		ft_ra(&(*list_a), 2);
	}
	else if ((*list_b)->n > (*list_a)->next->next->next->n)
	{
		ft_pa(&(*list_a), &(*list_b), 1);
		ft_ra(&(*list_a), 1);
	}
}
