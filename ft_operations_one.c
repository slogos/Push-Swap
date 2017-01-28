/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 22:55:57 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:02:54 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_pa(t_list **list_a, t_list **list_b, int i)
{
	while (i)
	{
		push_a(&(*list_a), &(*list_b));
		ft_printf("pa\n");
		i--;
	}
}

void	ft_pb(t_list **list_a, t_list **list_b, int i)
{
	while (i)
	{
		push_b(&(*list_a), &(*list_b));
		ft_printf("pb\n");
		i--;
	}
}

void	ft_ra(t_list **list_a, int i)
{
	while (i)
	{
		rotate_ra(&(*list_a));
		ft_printf("ra\n");
		i--;
	}
}

void	ft_rb(t_list **list_b, int i)
{
	while (i)
	{
		rotate_rb(&(*list_b));
		ft_printf("rb\n");
		i--;
	}
}

void	ft_rr(t_list **list_a, t_list **list_b, int i)
{
	while (i)
	{
		rotate_rr(&(*list_a), &(*list_b));
		ft_printf("rr\n");
		i--;
	}
}
