/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adalgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:24:35 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/29 20:14:45 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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


void	push_all_poop(t_nb *stacks[2], size_t size[2])
{
	size_t	len = size[A];

	while (len--)
	{
		if (stacks[A]->to_swap)
		{
			pe_order(stacks, size, sa);
			pe_order(stacks, size, ra);
			pe_order(stacks, size, ra);
			if (len)
				--len;
		}
		else if (stacks[A]->in_lssl)
			pe_order(stacks, size, ra);
		else
			pe_order(stacks, size, pb);
	}
	// exit();
}

void	init_best(t_bmove *bmove)
{
	bmove->n_rr = 0;
	bmove->n_ra = 0;
	bmove->n_rb = 0;
	bmove->n_rra = 0;
	bmove->n_rrb = 0;
	bmove->n_rrr = 0;
	bmove->n_tt = 0;
}

t_nb	*max_of_stack(t_nb *stack)
{
	const t_nb	*start = stack;
	t_nb	*max;

	max = stack;
	stack = stack->above;
	while (stack != start)
	{
		if (stack->nb > max->nb)
			max = stack;
		stack = stack->above;
	}
	return (max);
}

t_nb	*min_of_stack(t_nb *stack)
{
	const t_nb	*start = stack;
	t_nb		*min;

	min = stack;
	stack = stack->above;
	while (stack != start)
	{
		if (stack->nb < min->nb)
			min = stack;
		stack = stack->above;
	}
	return (min);
}
size_t	distance_from_top(t_nb *stack, t_nb *goal);

size_t	distance_to_bellow(int goal, t_nb *a)
{
	const t_nb	*max_s = max_of_stack(a);
	const t_nb	*min_s = min_of_stack(a);
	size_t	distance;

	distance = 0;
	if (max_s->nb < goal || goal < min_s->nb)
		return (distance_from_top(a, (t_nb *)min_s));
	while (a)
	{
		// if (goal > a->nb && goal > a->above->nb && a->above->nb > a->nb)
		// 	break ;
		// if (goal < a->nb && goal < a->above->nb && a->above->nb > a->nb)
		// 	break ;
		// fprintf(stderr, "--- %lu\n", distance);
		if (a->nb > goal && (a->above->nb < goal ))
			break ;
		++distance;
		a = a->bellow;
		// if (distance > 10)
		// 	break ;
	}
	return (distance);
}
// 0123 56 | 4

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

size_t min_sizet(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
int	test(t_bmove *b_move)
{
	const size_t	cost_rr = b_move->n_ra + b_move->n_rb - b_move->n_rr;
	const size_t	cost_rrr  = b_move->n_rra + b_move->n_rrb - b_move->n_rrr;
	const size_t	cost_ra_rrb = b_move->n_ra + b_move->n_rrb;
	const size_t	cost_rra_rb = b_move->n_rra + b_move->n_rb;

	fprintf(stderr, "{%lu|%lu|%lu|%lu}\n", cost_rr, cost_rrr, cost_ra_rrb, cost_rra_rb);
	if (cost_rr <= cost_ra_rrb && cost_rr <= cost_rra_rb && cost_rr <= cost_rrr)
	{
		b_move->n_tt = cost_rr;
		return (B_RR);
	}
	if (cost_rrr <= cost_ra_rrb && cost_rrr <= cost_rra_rb && cost_rrr <= cost_rr)
	{
		b_move->n_tt = cost_rrr;
		return (B_RRR);
	}
	if (cost_ra_rrb <= cost_rra_rb && cost_ra_rrb <= cost_rrr && cost_ra_rrb <= cost_rr)
	{
		b_move->n_tt = cost_ra_rrb;
		return (B_RA_RRB);
	}
	b_move->n_tt = cost_rra_rb;
	return (B_RRA_RB);
}
t_bmove	find_cost(t_nb	*act, t_nb *stacks[2], size_t size[2])
{
	t_bmove	best;

	init_best(&best);
	best.n_rb = distance_from_top(stacks[B], act);
	best.n_rrb = size[B] - best.n_rb;
	best.n_ra = distance_to_bellow(act->nb, stacks[A]);
	best.n_rra =  size[A] - best.n_ra;
	
	best.n_rr = min_sizet(best.n_rb, best.n_ra);
	best.n_rrr = min_sizet(best.n_rrb, best.n_rra);
	best.best = test(&best);
	// fprintf(stderr, "%d:  %lu %lu (%lu) | %lu %lu (%lu)\n", act->nb, best.n_rb, best.n_ra, best.n_rr, best.n_rrb, best.n_rra, best.n_rrr);
	// fprintf(stderr, "%s:%lu\n\n", (char *[]){"RR", "RRR", "RA_RB", "RRA_RB"}[best.best], best.n_tt);
	// exit(0);
	return (best);
}

void	exec_best(t_bmove best, t_nb *stacks[2], size_t size[2])
{
	fprintf(stderr, "CACACACA:  %lu %lu (%lu) | %lu %lu (%lu)\n", best.n_rb, best.n_ra, best.n_rr, best.n_rrb, best.n_rra, best.n_rrr);
	fprintf(stderr, "%s:%lu\n\n", (char *[]){"RR", "RRR", "RA_RB", "RRA_RB"}[best.best], best.n_tt);
	if (best.best == B_RA_RRB)
	{
		while (best.n_ra--)
			pe_order(stacks, size, ra);
		while (best.n_rrb--)
			pe_order(stacks, size, rrb);
	}
	if (best.best == B_RRA_RB)
	{
		while (best.n_rra--)
			pe_order(stacks, size, rra);
		while (best.n_rb--)
			pe_order(stacks, size, rb);
	}
	if (best.best == B_RR)
	{
		best.n_ra -= best.n_rr;
		best.n_rb -= best.n_rr;
		while (best.n_rr--)
			pe_order(stacks, size, rr);
		while (best.n_ra--)
			pe_order(stacks, size, ra);
		while (best.n_rb--)
			pe_order(stacks, size, rb);
	}
	if (best.best == B_RRR)
	{
		best.n_rra -= best.n_rrr;
		best.n_rrb -= best.n_rrr;
		while (best.n_rrr--)
			pe_order(stacks, size, rrr);
		while (best.n_rra--)
			pe_order(stacks, size, rra);
		while (best.n_rrb--)
			pe_order(stacks, size, rrb);
	}
	pe_order(stacks, size, pa);
}

t_bmove	find_best_move(t_nb *stacks[2], size_t size[2])
{
	t_bmove	act;
	t_bmove	best;
	size_t	ib;
	t_nb	*b;

	b = stacks[B];
	ib = size[B];
	best.n_tt = S_INT32_MAX;
	while (ib --)
	{
		act = find_cost(b, stacks, size);
		if (act.n_tt < best.n_tt)
			best = act;
		b = b->bellow;
	}
	fprintf(stderr, "%s:%lu\n\n", (char *[]){"RR", "RRR", "RA_RB", "RRA_RB"}[best.best], best.n_tt);
	exec_best(best, stacks, size);
	return (best);
}

size_t	get_distance_0(t_nb *stack)
{
	size_t	distance;

	distance = 0;
	while (1)
	{
		if (stack->nb == 0)
			return (distance);
		++distance;
		stack = stack->bellow;
	}
}

void	adalgo(t_nb *stacks[2], size_t size[2])
{
	size_t	n_ra;
	size_t	n_rra;

	push_all_poop(stacks, size);
	while (size[B])
		find_best_move(stacks, size);
	n_ra = get_distance_0(stacks[A]);
	n_rra = size[A] - n_ra;
	if (n_ra < n_rra)
	{
		while (n_ra--)
			pe_order(stacks, size, ra);
	}
	else
	{
		while (n_rra--)
			pe_order(stacks, size, rra);
	}
}
