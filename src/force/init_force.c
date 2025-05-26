/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:16:37 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/26 13:20:55 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_orders(t_order orders[MAX_DEPTH], size_t nb_order)
{
	size_t	i;

	i = 0;
	while (i <  nb_order)
	{
		p_order(orders[i]);
		++i;
	}
}

int	start_brutforce(t_nb *stack[2], size_t size[2])
{
	t_force	force;

	force.depth = 0;
	force.max_depth = 0;
	force.stacks = (t_nb **)stack;
	force.size = size;
	force.stupidcount = 0;
	force.nmd = 0;
	while (force.max_depth <= MAX_DEPTH)
	{
		// fprintf(stderr, "\n----------%zu\n", force.max_depth);
		if (depth_0(&force, 0))
		{
			fprintf(stderr, "%lu|%lu\n\n", force.stupidcount, force.nmd);
			print_orders(force.orders, force.max_depth);
			return (1);
		}
		++force.max_depth;
	}
	fprintf(stderr, "%lu|%lu\n\n", force.stupidcount, force.nmd);
	return (0);
}
