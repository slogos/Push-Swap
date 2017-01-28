/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 01:17:29 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:00:45 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_del_array(char ***array)
{
	int i;

	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
}

void	ft_lstdel_t(t_list **list)
{
	t_list *list_remove;

	list_remove = *list;
	while (list_remove->next)
	{
		list_remove = (*list)->next;
		free(*list);
		*list = list_remove;
	}
	free(*list);
}

void	ft_lstdel_m(t_rot **list)
{
	t_rot *list_remove;

	list_remove = *list;
	while (list_remove->next)
	{
		list_remove = (*list)->next;
		free(*list);
		*list = list_remove;
	}
	free(*list);
}

void	ft_lstdel_tmp(t_rot **list)
{
	t_rot *list_remove;

	list_remove = *list;
	while (list_remove->next)
	{
		list_remove = (*list)->next;
		free((*list)->char_del);
		free(*list);
		*list = list_remove;
	}
	free(*list);
}

void	ft_end(t_list **list, char *str)
{
	ft_lstdel_t(&(*list));
	free(str);
	ft_printf("Error\n");
}
