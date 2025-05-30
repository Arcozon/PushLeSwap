/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adalgo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:48:21 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:49:14 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADALGO_H
# define ADALGO_H

enum
{
	B_RR,
	B_RRR,
	B_RA_RRB,
	B_RRA_RB
};

typedef struct s_bmove
{
	size_t	n_ra;
	size_t	n_rb;
	size_t	n_rr;
	size_t	n_rra;
	size_t	n_rrb;
	size_t	n_rrr;
	size_t	n_tt;
	int		best;
}	t_bmove;

int		find_min_cost(t_bmove *b_move);
t_bmove	calc_cost(t_nb	*act, t_nb *stacks[2], size_t size[2]);
void	find_sorted_list(t_nb *a);
int		find_min_cost(t_bmove *b_move);
t_bmove	calc_cost(t_nb	*act, t_nb *stacks[2], size_t size[2]);
void	exec_best(t_bmove best, t_nb *stacks[2], size_t size[2]);
size_t	get_distance_0(t_nb *stack);
t_nb	*min_of_stack(t_nb *stack);
t_nb	*max_of_stack(t_nb *stack);
void	init_best(t_bmove *bmove);
void	adalgo(t_nb *stacks[2], size_t size[2]);
t_nb	*find_max_lssl(t_nb *a);
void	push_all_poop(t_nb *stacks[2], size_t size[2]);

#endif
