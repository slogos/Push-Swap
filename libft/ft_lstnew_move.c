/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:51:21 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:19:27 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstnew_move(t_rot **list)
{
	t_rot	*new;

	new = NULL;
	if (*list)
	{
		new = *list;
		while (new->next)
			new = new->next;
		new->next = (t_rot*)malloc(sizeof(t_rot));
		new->next->next = NULL;
		return ;
	}
	*list = (t_rot*)malloc(sizeof(t_rot));
	(*list)->next = NULL;
	return ;
}
