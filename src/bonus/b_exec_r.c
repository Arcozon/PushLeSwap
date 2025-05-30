/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exec_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:21:18 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:00:46 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	e_ra(t_nb *stacks[2], size_t size[2])
{
	if (!size[A])
		return ;
	stacks[A] = stacks[A]->bellow;
}

void	e_rb(t_nb *stacks[2], size_t size[2])
{
	if (!size[B])
		return ;
	stacks[B] = stacks[B]->bellow;
}

void	e_rr(t_nb *stacks[2], size_t size[2])
{
	e_ra(stacks, size);
	e_rb(stacks, size);
}

void	e_order(t_nb *stacks[2], size_t size[2], t_order to_exec)
{
	static void	(*exec[NB_ORDER])(t_nb *[2], size_t [2]) = {e_pa, e_pb, e_sa,
		e_sb, e_ss, e_ra, e_rb, e_rr, e_rra, e_rrb, e_rrr};

	exec[to_exec](stacks, size);
}
