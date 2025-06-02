/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brutforce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:35:32 by gaeudes           #+#    #+#             */
/*   Updated: 2025/06/02 13:04:35 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static inline void	revert_order(t_nb *stacks[2], size_t size[2],
	t_order to_rev)
{
	static void	(*rev[NB_ORDER])(t_nb *[2], size_t [2]) = {e_pb, e_pa, e_sa,
		e_sb, e_ss, e_rra, e_rrb, e_rrr, e_ra, e_rb, e_rr};

	rev[to_rev](stacks, size);
}

static inline void	exec_order(t_nb *stacks[2], size_t size[2], t_order to_exec)
{
	static void	(*exec[NB_ORDER])(t_nb *[2], size_t [2]) = {e_pa, e_pb, e_sa,
		e_sb, e_ss, e_ra, e_rb, e_rr, e_rra, e_rrb, e_rrr};

	exec[to_exec](stacks, size);
}

// I did this myself and its pain
static inline int	is_order_relevant(t_order order, t_order last,
	size_t size[2])
{
	static char	relevant[NB_ORDER + 1][NB_ORDER + 1] = {
		"10111111111",
		"01111111111",
		"11010111111",
		"11100111111",
		"11000111111",
		"11111111010",
		"11111111100",
		"11111111000",
		"11111010111",
		"11111100111",
		"11111000111",
	};
	static char	need_size_a[NB_ORDER] = "00101101101";
	static char	need_size_b[NB_ORDER] = "00011011011";

	if (order == pa && !size[B])
		return (0);
	if (order == pb && !size[A])
		return (0);
	if (need_size_a[order] == '1' && size[A] <= 1)
		return (0);
	if (need_size_b[order] == '1' && size[B] <= 1)
		return (0);
	return (relevant[order][last] == '1');
}

int	bf(t_force *force, size_t actual_depth)
{
	t_order	try;

	if (is_sorted(force->stacks, force->size))
		return (1);
	if (actual_depth >= force->max_depth)
	{
		revert_order(force->stacks, force->size,
			force->orders[actual_depth - 1]);
		return (0);
	}
	try = -1;
	while (++try < end)
	{
		if (is_order_relevant(try, force->orders[actual_depth - 1],
				force->size))
		{
			force->orders[actual_depth] = try;
			exec_order(force->stacks, force->size, try);
			if (bf(force, actual_depth + 1))
				return (1);
		}
	}
	revert_order(force->stacks, force->size, force->orders[actual_depth - 1]);
	return (0);
}

int	depth_0(t_force *force, size_t actual_depth)
{
	static char	relevant[NB_ORDER] = "01100100100";

	if (is_sorted(force->stacks, force->size))
		return (1);
	if (actual_depth >= force->max_depth)
		return (0);
	force->orders[actual_depth] = 0;
	while (force->orders[actual_depth] < end)
	{
		if (relevant[force->orders[actual_depth]] == '1')
		{
			exec_order(force->stacks, force->size, force->orders[actual_depth]);
			if (bf(force, actual_depth + 1))
				return (1);
		}
		++force->orders[actual_depth];
	}
	return (0);
}
