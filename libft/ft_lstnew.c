/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:51:21 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:20:42 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstnew(t_list **list)
{
	t_list	*new;

	new = NULL;
	if (*list)
	{
		new = *list;
		while (new->next)
			new = new->next;
		new->next = (t_list*)malloc(sizeof(t_list));
		new->next->next = NULL;
		return ;
	}
	*list = (t_list*)malloc(sizeof(t_list));
	(*list)->next = NULL;
	return ;
}
