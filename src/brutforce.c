/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brutforce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:35:32 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/25 19:01:59 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_orders(t_order orders[MAX_DEPTH])
{
	size_t	i;

	i = 0;
	while (orders[i] != end)
	{
		print_one_order(orders[i]);
		++i;
	}
}

static inline void	revert_order(t_nb *stacks[2], size_t size[2], t_order to_rev)
{
	static void	(*rev[NB_ORDER])(t_nb *[2], size_t [2]) = {e_pb, e_pb, e_sa,
		e_sb, e_ss, e_rra, e_rrb, e_rrr, e_ra, e_rb, e_rr};

	rev[to_rev](stacks, size);
}

static inline void	exec_order(t_nb *stacks[2], size_t size[2], t_order to_exec)
{
	static void	(*exec[NB_ORDER])(t_nb *[2], size_t [2]) = {e_pa, e_pb, e_sa,
		e_sb, e_ss, e_ra, e_rb, e_rr, e_rra, e_rrb, e_rra};

	exec[to_exec](stacks, size);
}

// I did this myself and its pain
static inline int	is_order_relevant(t_order order, t_order last, size_t size[2])
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

	if (order == pa && !size[b])
		return (0);
	if (order == pb && !size[a])
		return (0);
	if (need_size_a[order] == '1' && size[a] <= 1)
		return (0);
	if (need_size_b[order] == '1' && size[b] <= 1)
		return (0);
	return (relevant[order][last] == '1');
}

int	bf(t_nb *stacks[2], size_t size[2], t_order orders[MAX_DEPTH], size_t depth)
{
	t_order	try;

	if (depth >= MAX_DEPTH)
	{
		revert_order(stacks, size, orders[MAX_DEPTH - 1]);
		return (0);
	}
	if (is_sorted(stacks, size))
		return (orders[depth] = end, 1);
	try = 0;
	while (try < end)
	{
		if (is_order_relevant(try, orders[depth - 1], size))
		{
			orders[depth] = try;
			exec_order(stacks, size, try);
			if (bf(stacks, size, orders, depth + 1))
				return (1);
		}
		++try;
	}
	revert_order(stacks, size, orders[depth - 1]);
	printf("%zu\n", depth);
	return (0);
}

int	start_brut_force(t_nb *stacks[2], size_t size[2])
{
	static char relevant[NB_ORDER] = "01100100100";
	t_order	orders[MAX_DEPTH];
	t_order	try;

	try = 0;
	if (is_sorted(stacks, size))
		return (1);
	while (try < end)
	{
		if (relevant[try] == '1')
		{
			orders[0] = try;
			exec_order(stacks, size, try);
			if (bf(stacks, size, orders, 1))
			{
				print_orders(orders);
				return (1);
			}
		}
		++try;
	}
	return (0);

}
