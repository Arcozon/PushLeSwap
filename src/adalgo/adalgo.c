/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adalgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:24:35 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/31 13:10:51 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_all_poop(t_nb *stacks[2], size_t size[2])
{
	const int	middle_b = (int)((size[A] + size[B]) * 56 / 100);
	size_t		len;

	len = size[A];
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
		{
			pe_order(stacks, size, pb);
			if (size[B] > 1 && stacks[B]->nb > middle_b)
				pe_order(stacks, size, rb);
		}
	}
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
		act = calc_cost(b, stacks, size);
		if (act.n_tt < best.n_tt)
			best = act;
		b = b->bellow;
	}
	exec_best(best, stacks, size);
	return (best);
}

void	adalgo(t_nb *stacks[2], size_t size[2])
{
	size_t	n_ra;
	size_t	n_rra;

	if (is_sorted(stacks, size))
		return ;
	find_sorted_list(stacks[A]);
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
