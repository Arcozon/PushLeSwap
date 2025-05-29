/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exec_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:07:24 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/29 20:59:15 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	e_order(t_nb *stacks[2], size_t size[2], t_order to_exec)
{
	static void	(*exec[NB_ORDER])(t_nb *[2], size_t [2]) = {e_pa, e_pb, e_sa,
		e_sb, e_ss, e_ra, e_rb, e_rr, e_rra, e_rrb, e_rrr};

	exec[to_exec](stacks, size);
}

void	p_order(t_order order)
{
	static char	*s_order[NB_ORDER] = {
		"pa\n",
		"pb\n",
		"sa\n",
		"sb\n",
		"ss\n",
		"ra\n",
		"rb\n",
		"rr\n",
		"rra\n",
		"rrb\n",
		"rrr\n",
	};
	static size_t	l_order[NB_ORDER] = {3,3,3,3,3,3,3,3,4,4,4};

	write(1, s_order[order], l_order[order]);
}

void	pe_order(t_nb *stacks[2], size_t size[2], t_order order)
{
	e_order(stacks, size, order);
	p_order(order);
}
