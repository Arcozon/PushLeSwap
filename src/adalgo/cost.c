/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:29:34 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:46:09 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	min_sizet(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	distance_from_top(t_nb *stack, t_nb *goal)
{
	size_t	distance;

	distance = 0;
	while (stack != goal)
	{
		++distance;
		stack = stack->bellow;
	}
	return (distance);
}

size_t	distance_to_bellow(int goal, t_nb *a)
{
	const t_nb	*max_s = max_of_stack(a);
	const t_nb	*min_s = min_of_stack(a);
	size_t		distance;

	distance = 0;
	if (max_s->nb < goal || goal < min_s->nb)
		return (distance_from_top(a, (t_nb *)min_s));
	while (a)
	{
		if (a->nb > goal && a->above->nb < goal)
			break ;
		++distance;
		a = a->bellow;
	}
	return (distance);
}

int	find_min_cost(t_bmove *b_move)
{
	const size_t	cost_rr = b_move->n_ra + b_move->n_rb - b_move->n_rr;
	const size_t	cost_rrr = b_move->n_rra + b_move->n_rrb - b_move->n_rrr;
	const size_t	cost_ra_rrb = b_move->n_ra + b_move->n_rrb;
	const size_t	cost_rra_rb = b_move->n_rra + b_move->n_rb;

	if (cost_rr <= cost_ra_rrb && cost_rr <= cost_rra_rb && cost_rr <= cost_rrr)
	{
		b_move->n_tt = cost_rr;
		return (B_RR);
	}
	if (cost_rrr <= cost_ra_rrb && cost_rrr <= cost_rra_rb
		&& cost_rrr <= cost_rr)
	{
		b_move->n_tt = cost_rrr;
		return (B_RRR);
	}
	if (cost_ra_rrb <= cost_rra_rb && cost_ra_rrb <= cost_rrr
		&& cost_ra_rrb <= cost_rr)
	{
		b_move->n_tt = cost_ra_rrb;
		return (B_RA_RRB);
	}
	b_move->n_tt = cost_rra_rb;
	return (B_RRA_RB);
}

t_bmove	calc_cost(t_nb	*act, t_nb *stacks[2], size_t size[2])
{
	t_bmove	best;

	init_best(&best);
	best.n_rb = distance_from_top(stacks[B], act);
	best.n_rrb = size[B] - best.n_rb;
	best.n_ra = distance_to_bellow(act->nb, stacks[A]);
	best.n_rra = size[A] - best.n_ra;
	best.n_rr = min_sizet(best.n_rb, best.n_ra);
	best.n_rrr = min_sizet(best.n_rrb, best.n_rra);
	best.best = find_min_cost(&best);
	return (best);
}
