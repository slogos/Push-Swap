/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 00:02:52 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 00:53:48 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_normal_printout(char **tmp, t_rot **begin_tmp_del, \
			t_list **list_a, t_list **list_b)
{
	char	**split;
	int		n;
	int		i;

	n = 0;
	i = ft_len(&(*list_a));
	split = ft_strsplit(*tmp, '|');
	ft_lstdel_tmp(&(*begin_tmp_del));
	while (split[n])
	{
		ft_check_operation(&split[n], &(*list_a), &(*list_b));
		free(split[n]);
		n++;
	}
	free(split);
	if ((*begin_tmp_del)->m != n)
	{
		ft_printf("Error\n");
	}
	else
		ft_check_output(&(*list_a), i);
}

void	ft_c_printout(char **tmp, t_rot **begin_tmp_del)
{
	char	**split;
	int		n;

	n = 0;
	split = ft_strsplit(*tmp, '|');
	ft_lstdel_tmp(&(*begin_tmp_del));
	while (split[n + 1])
	{
		ft_printf("%s ", split[n]);
		free(split[n]);
		n++;
	}
	ft_printf("\n\e[38;5;156;1;3m%C  %s %C\e[0m\n", 9969, split[n], 9969);
	free(split[n]);
	free(split);
}

void	ft_check_output_v(t_list **list_a, int i)
{
	t_list	*swap;
	int		n;

	n = 1;
	swap = *list_a;
	if (!swap)
		ft_printf("KO\n");
	else
	{
		while (swap->next)
		{
			n++;
			if (swap->n > swap->next->n)
			{
				ft_printf("KO\n");
				return ;
			}
			swap = swap->next;
		}
		if (i == n)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
}

void	ft_check_output(t_list **list_a, int i)
{
	t_list	*swap;
	int		n;

	n = 0;
	swap = *list_a;
	while (swap)
	{
		n++;
		if (swap->next && swap->n > swap->next->n)
		{
			ft_printf("KO\n");
			return ;
		}
		swap = swap->next;
	}
	if (i == n)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
