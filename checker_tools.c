/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 23:57:53 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 00:56:04 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_first_check(t_list **list_a, t_list **list_b)
{
	char	*line;
	int		i;

	line = NULL;
	i = ft_len(&(*list_a));
	while (1)
	{
		get_next_line(1, &line);
		if (!ft_strcmp(line, "execute"))
		{
			ft_check_output_v(&(*list_a), i);
			exit(1);
		}
		if (!ft_validate_input(&line))
			printf("!!! Invalid operation !!!\n");
		ft_check_operation(&line, &(*list_a), &(*list_b));
		ft_print_out(&(*list_a), &(*list_b));
	}
}

void	ft_seconde_check(char **tmp, t_rot **tmp_del, t_rot **begin_tmp_del)
{
	char *line;

	line = NULL;
	*tmp = (char *)malloc(sizeof(char));
	(*tmp)[0] = '\0';
	(*tmp_del)->char_del = *tmp;
	*tmp_del = (*tmp_del)->next;
	get_next_line(0, &line);
	ft_lstnew_move(&(*tmp_del));
	*tmp = ft_strjoin(*tmp, line);
	(*tmp_del)->char_del = *tmp;
	*tmp_del = (*tmp_del)->next;
	*tmp = ft_strjoin(*tmp, "|");
	ft_lstnew_move(&(*tmp_del));
	(*tmp_del)->char_del = *tmp;
	*tmp_del = (*tmp_del)->next;
	ft_gnl_loop_c(tmp, &(*tmp_del));
	ft_c_printout(tmp, &(*begin_tmp_del));
}

void	ft_third_check(char **tmp, t_rot **tmp_del, t_rot **begin_tmp_del)
{
	char *line;

	line = NULL;
	*tmp = (char *)malloc(sizeof(char));
	(*tmp)[0] = '\0';
	(*tmp_del)->char_del = *tmp;
	*tmp_del = (*tmp_del)->next;
	get_next_line(0, &line);
	if (!ft_validate_input(&line))
	{
		ft_printf("Error\n");
		exit(1);
	}
	ft_lstnew_move(&(*tmp_del));
	*tmp = ft_strjoin(*tmp, line);
	(*tmp_del)->char_del = *tmp;
	*tmp_del = (*tmp_del)->next;
	*tmp = ft_strjoin(*tmp, "|");
	ft_lstnew_move(&(*tmp_del));
	(*tmp_del)->char_del = *tmp;
	*tmp_del = (*tmp_del)->next;
	ft_gnl_loop(tmp, &(*tmp_del), &(*begin_tmp_del));
}

void	ft_gnl_loop(char **tmp, t_rot **tmp_del, t_rot **begin_tmp_del)
{
	char *line;

	(*begin_tmp_del)->m = 1;
	while (1)
	{
		get_next_line(0, &line);
		*tmp = ft_strjoin(*tmp, line);
		ft_lstnew_move(&(*tmp_del));
		(*tmp_del)->char_del = *tmp;
		*tmp_del = (*tmp_del)->next;
		*tmp = ft_strjoin(*tmp, "|");
		ft_lstnew_move(&(*tmp_del));
		(*tmp_del)->char_del = *tmp;
		*tmp_del = (*tmp_del)->next;
		if (!ft_validate_input(&line))
			break ;
		(*begin_tmp_del)->m++;
	}
}

void	ft_gnl_loop_c(char **tmp, t_rot **tmp_del)
{
	char *line;

	while (1)
	{
		get_next_line(0, &line);
		*tmp = ft_strjoin(*tmp, line);
		ft_lstnew_move(&(*tmp_del));
		(*tmp_del)->char_del = *tmp;
		*tmp_del = (*tmp_del)->next;
		*tmp = ft_strjoin(*tmp, "|");
		ft_lstnew_move(&(*tmp_del));
		(*tmp_del)->char_del = *tmp;
		*tmp_del = (*tmp_del)->next;
		if (!ft_validate_input(&line))
			break ;
	}
}
