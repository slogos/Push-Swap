/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 00:52:23 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:15:17 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/ft_printf.h"
# include "libft/libft.h"

void	swap_a(t_list **list_a);
void	swap_b(t_list **list_b);
void	swap_ss(t_list **list_a, t_list **list_b);
void	push_b(t_list **list_a, t_list **list_b);
void	push_a(t_list **list_a, t_list **list_b);
void	rotate_ra(t_list **list_a);
void	rotate_rb(t_list **list_b);
void	rotate_rr(t_list **list_a, t_list **list_b);
void	rotate_rra(t_list **list_a);
void	rotate_rrb(t_list **list_b);
void	rotate_rrr(t_list **list_a, t_list **list_b);
void	ft_sa(t_list **list_a, int i);
void	ft_sb(t_list **list_b, int i);
void	ft_pa(t_list **list_a, t_list **list_b, int i);
void	ft_pb(t_list **list_a, t_list **list_b, int i);
void	ft_ra(t_list **list_a, int i);
void	ft_rb(t_list **list_b, int i);
void	ft_rr(t_list **list_a, t_list **list_b, int i);
void	ft_rra(t_list **list_a, int i);
void	ft_rrb(t_list **list_b, int i);
void	ft_rrr(t_list **list_a, t_list **list_b, int i);
void	ft_init_list(t_list **list_a, t_list **list_b);
int		check_int_size(char *str, t_list **list_a, int *i);
int		check_minus_zero(char *str);
int		check_digit(char *str);
int		check_match(t_list **list_a);
int		check_elements(t_list **list_a);
void	ft_brut_force(t_list **list_a, t_list **list_b);
void	solve_two(t_list **list_a);
void	solve_three(t_list **list_a);
void	solve_three_rev(t_list **list_b);
void	ft_find_b_position(t_list **list_a, t_list **list_b);
void	ft_find_seconde_b_position(t_list **list_a, t_list **list_b);
void	ft_find_seconde_b_position_part_two(t_list **list_a, t_list **list_b);
void	ft_solve_three_one(t_list **list_a);
void	ft_solve_three_five(t_list **list_a);
void	ft_solve_three_one_rev(t_list **list_b);
void	ft_solve_three_four_rev(t_list **list_b);
void	ft_start_three(t_list **list_a, t_list **list_b);
void	ft_next_list(t_rot **list_p, int *i);
void	ft_del_array(char ***array);
void	ft_lstdel_t(t_list **list);
void	ft_lstdel_m(t_rot **list);
void	ft_lstdel_tmp(t_rot **list);
void	ft_lstdel_all(t_list **list_a, t_rot **best);
void	ft_end(t_list **list, char *str);
void	ft_load_best(t_rot **swap, t_rot **best);
void	ft_find_best(t_rot **list, t_rot **best);
void	ft_load_moves(int *tab, t_rot **list);
void	ft_load_moves_part_two(int *tab, t_rot **list);
void	ft_load_zero(t_list **list_a, t_list **list_b, t_rot **list_p);
void	ft_best_move(t_rot **list);
int		ft_len(t_list **list);
void	find_max_position(t_list **list_b, t_rot **list);
void	find_min_position(t_list **list_b, t_rot **list);
int		max_stack(t_list **list);
int		min_stack(t_list **list);
void	verify_position(t_list **list_a, t_list **list_b, t_rot **list);
int		ft_solver_min_max(t_list **list_a, t_list **list_b, \
			t_list **swap_a, t_rot **list_p);
int		ft_solver_all(t_list **swap_a, t_list **swap_b, t_rot **list_p);
void	ft_solve(t_list **list_a, t_list **list_b, t_rot **list, \
			t_rot **best);
void	ft_solve_end(t_list **list_a, t_list **list_b, t_rot **best, \
			int *i);
int		verify_order(t_list **list_a);
void	ft_print_out(t_list **list_a, t_list **list_b);
void	ft_execute(char **s);
void	ft_first_check(t_list **list_a, t_list **list_b);
void	ft_seconde_check(char **tmp, t_rot **tmp_del, \
			t_rot **begin_tmp_del);
void	ft_third_check(char **tmp, t_rot **tmp_del, t_rot **begin_tmp_del);
void	ft_gnl_loop(char **tmp, t_rot **tmp_del, t_rot **begin_tmp_del);
void	ft_gnl_loop_c(char **tmp, t_rot **tmp_del);
void	ft_normal_printout(char **tmp, t_rot **begin_tmp_del, \
			t_list **list_a, t_list **list_b);
void	ft_c_printout(char **tmp, t_rot **begin_tmp_del);
void	ft_check_output_v(t_list **list_a, int i);
void	ft_check_output(t_list **list_a, int i);
int		ft_validate_input(char **line);
void	ft_check_operation(char **line, t_list **list_a, t_list **list_b);
void	verify_order_checker(t_list **list_a);
void	ft_init_list_checker(t_rot **tmp_del, t_rot **begin_tmp_del);

#endif
