/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:42:57 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:54:57 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORCE_H
# define FORCE_H

# include "orders.h"

# define MAX_DEPTH 14

typedef struct s_nb	t_nb;

typedef struct s_force
{
	int		depth;
	size_t	max_depth;

	t_order	orders[MAX_DEPTH];

	t_nb	**stacks;
	size_t	*size;
}	t_force;

int		bf(t_force *force, size_t actual_depth);
int		start_brutforce(t_nb *stack[2], size_t size[2]);
int		depth_0(t_force *force, size_t actual_depth);

#endif
