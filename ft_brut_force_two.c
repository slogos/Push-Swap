/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 00:29:31 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:00:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_solve_three_one(t_list **list_a)
{
	ft_ra(&(*list_a), 1);
	ft_sa(&(*list_a), 1);
}

void	ft_solve_three_five(t_list **list_a)
{
	ft_rra(&(*list_a), 1);
	ft_sa(&(*list_a), 1);
}

void	ft_solve_three_one_rev(t_list **list_b)
{
	ft_rb(&(*list_b), 1);
	ft_sb(&(*list_b), 1);
	ft_rrb(&(*list_b), 1);
}

void	ft_solve_three_four_rev(t_list **list_b)
{
	ft_sb(&(*list_b), 1);
	ft_rrb(&(*list_b), 1);
}

void	ft_start_three(t_list **list_a, t_list **list_b)
{
	ft_pb(&(*list_a), &(*list_b), 3);
	if (!((*list_b)->n > (*list_b)->next->n && \
		(*list_b)->next->n > (*list_b)->next->next->n))
		solve_three_rev(&(*list_b));
}
