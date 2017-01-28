/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 22:58:27 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:03:06 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_sa(t_list **list_a, int i)
{
	while (i)
	{
		swap_a(&(*list_a));
		ft_printf("sa\n");
		i--;
	}
}

void	ft_sb(t_list **list_b, int i)
{
	while (i)
	{
		swap_b(&(*list_b));
		ft_printf("sb\n");
		i--;
	}
}

void	ft_rra(t_list **list_a, int i)
{
	while (i)
	{
		rotate_rra(&(*list_a));
		ft_printf("rra\n");
		i--;
	}
}

void	ft_rrb(t_list **list_b, int i)
{
	while (i)
	{
		rotate_rrb(&(*list_b));
		ft_printf("rrb\n");
		i--;
	}
}

void	ft_rrr(t_list **list_a, t_list **list_b, int i)
{
	while (i)
	{
		rotate_rrr(&(*list_a), &(*list_b));
		ft_printf("rrr\n");
		i--;
	}
}
