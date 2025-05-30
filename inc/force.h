/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:42:57 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 12:30:47 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORCE_H
# define FORCE_H

// # include "pushswap.h"

# define MAX_DEPTH 14

typedef enum e_order
{
	pa,
	pb,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	end
}	t_order;

typedef struct s_nb	t_nb;

typedef struct s_force
{
	int	depth;
	size_t	max_depth;

	t_order	orders[MAX_DEPTH];

	t_nb	**stacks;
	size_t	*size;
	size_t	stupidcount;
	size_t	nmd;
}	t_force;

int		bf(t_force *force, size_t actual_depth);
int		start_brutforce(t_nb *stack[2], size_t size[2]);
int		depth_0(t_force *force, size_t actual_depth);

#endif
