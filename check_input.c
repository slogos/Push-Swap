/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 00:04:45 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 00:47:29 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		ft_validate_input(char **line)
{
	if (!ft_strcmp(*line, "pa") || !ft_strcmp(*line, "pb") || \
		!ft_strcmp(*line, "sa") || !ft_strcmp(*line, "sb") || \
		!ft_strcmp(*line, "ss") || !ft_strcmp(*line, "ra") || \
		!ft_strcmp(*line, "rb") || !ft_strcmp(*line, "rr") || \
		!ft_strcmp(*line, "rra") || !ft_strcmp(*line, "rrb") || \
		!ft_strcmp(*line, "rrr"))
		return (1);
	return (0);
}

void	ft_check_operation(char **line, t_list **list_a, t_list **list_b)
{
	!ft_strcmp(*line, "pa") ? push_a(&(*list_a), &(*list_b)) : 0;
	!ft_strcmp(*line, "pb") ? push_b(&(*list_a), &(*list_b)) : 0;
	!ft_strcmp(*line, "sa") ? swap_a(&(*list_a)) : 0;
	!ft_strcmp(*line, "sb") ? swap_b(&(*list_b)) : 0;
	!ft_strcmp(*line, "ss") ? swap_ss(&(*list_a), &(*list_b)) : 0;
	!ft_strcmp(*line, "ra") ? rotate_ra(&(*list_a)) : 0;
	!ft_strcmp(*line, "rb") ? rotate_rb(&(*list_b)) : 0;
	!ft_strcmp(*line, "rr") ? rotate_rr(&(*list_a), &(*list_b)) : 0;
	!ft_strcmp(*line, "rra") ? rotate_rra(&(*list_a)) : 0;
	!ft_strcmp(*line, "rrb") ? rotate_rrb(&(*list_b)) : 0;
	!ft_strcmp(*line, "rrr") ? rotate_rrr(&(*list_a), &(*list_b)) : 0;
}

void	verify_order_checker(t_list **list_a)
{
	t_list *swap;

	swap = *list_a;
	while (swap->next)
	{
		if (swap->n > swap->next->n)
			return ;
		swap = swap->next;
	}
	ft_printf("OK\n");
	exit(1);
}

void	ft_init_list_checker(t_rot **tmp_del, t_rot **begin_tmp_del)
{
	*tmp_del = NULL;
	ft_lstnew_move(&(*tmp_del));
	*begin_tmp_del = *tmp_del;
}
