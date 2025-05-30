/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:34:47 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:40:19 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exe_ra_rrb(t_bmove best, t_nb *stacks[2], size_t size[2])
{
	while (best.n_ra--)
		pe_order(stacks, size, ra);
	while (best.n_rrb--)
		pe_order(stacks, size, rrb);
}

void	exe_rra_rb(t_bmove best, t_nb *stacks[2], size_t size[2])
{
	while (best.n_rra--)
		pe_order(stacks, size, rra);
	while (best.n_rb--)
		pe_order(stacks, size, rb);
}

void	exe_rr(t_bmove best, t_nb *stacks[2], size_t size[2])
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

void	exe_rrr(t_bmove best, t_nb *stacks[2], size_t size[2])
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

void	exec_best(t_bmove best, t_nb *stacks[2], size_t size[2])
{
	if (best.best == B_RA_RRB)
		exe_ra_rrb(best, stacks, size);
	else if (best.best == B_RRA_RB)
		exe_rra_rb(best, stacks, size);
	else if (best.best == B_RR)
		exe_rr(best, stacks, size);
	else if (best.best == B_RRR)
		exe_rrr(best, stacks, size);
	pe_order(stacks, size, pa);
}
