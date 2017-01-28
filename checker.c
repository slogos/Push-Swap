/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:49:15 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 00:51:28 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	console(t_list **list_a, t_list **list_b, int ac, char **av)
{
	t_rot	*tmp_del;
	t_rot	*begin_tmp_del;
	char	*tmp;

	ft_init_list_checker(&tmp_del, &begin_tmp_del);
	verify_order_checker(&(*list_a));
	if (ac == 3 && !ft_strcmp(av[2], "-v"))
		ft_first_check(&(*list_a), &(*list_b));
	else if (ac == 3 && !ft_strcmp(av[2], "-c"))
		ft_seconde_check(&tmp, &tmp_del, &begin_tmp_del);
	else if (ac == 2)
	{
		ft_third_check(&tmp, &tmp_del, &begin_tmp_del);
		ft_normal_printout(&tmp, &begin_tmp_del, &(*list_a), &(*list_b));
	}
}

int		main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	char	*str;
	int		i;

	i = 0;
	if (av[1] == NULL)
		return (0);
	ft_init_list(&list_a, &list_b);
	str = ft_strdup(av[1]);
	if (ac > 2)
		ft_execute(&av[2]);
	if (check_digit(str) && check_minus_zero(str) && \
		check_int_size(str, &list_a, &i) && check_match(&list_a))
		console(&list_a, &list_b, ac, &(*av));
	else
		ft_end(&list_a, str);
	return (0);
}
