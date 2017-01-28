/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 03:14:09 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 00:49:50 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		check_int_size(char *str, t_list **list_a, int *i)
{
	t_list	*begin;
	char	**array;
	char	c;

	*i = 0;
	c = ' ';
	begin = *list_a;
	array = ft_strsplit(str, c);
	while (array[*i])
	{
		begin->n = ft_atoi(array[*i]);
		if (begin->n < -2147483648 || begin->n > 2147483647)
			return (0);
		(*i)++;
		if (array[*i] != '\0')
			ft_lstnew(&begin);
		begin = begin->next;
	}
	ft_del_array(&array);
	return (1);
}

int		check_minus_zero(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			return (0);
		else if ((ft_isdigit(str[i]) == 1) && (str[i + 1] == '-'))
			return (0);
		else if (str[i] == '-' && str[i + 1] == '0')
			return (0);
		i++;
	}
	return (1);
}

int		check_digit(char *str)
{
	int i;
	int count;
	int count_nb;

	i = 0;
	count = 0;
	count_nb = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			count_nb++;
		if (str[i] == ' ' || str[i] == '-')
			count++;
		i++;
	}
	if (count_nb && (count + count_nb) == ft_strlen(str))
		return (1);
	else
		return (0);
}

int		check_match(t_list **list_a)
{
	t_list *swap;
	t_list *begin;

	swap = *list_a;
	begin = *list_a;
	while (begin->next)
	{
		swap = begin->next;
		while (swap)
		{
			if (begin->n == swap->n)
			{
				return (0);
			}
			swap = swap->next;
		}
		begin = begin->next;
	}
	return (1);
}

int		check_elements(t_list **list_a)
{
	t_list	*swap;
	int		i;

	i = 0;
	swap = *list_a;
	while (swap)
	{
		i++;
		swap = swap->next;
	}
	if (i == 2)
		return (2);
	else if (i == 3)
		return (3);
	else if (i == 4)
		return (4);
	else if (i == 5)
		return (5);
	return (0);
}
