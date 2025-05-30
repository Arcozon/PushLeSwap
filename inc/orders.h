/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:46:26 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:50:46 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDERS_H
# define ORDERS_H

# define NB_ORDER 11

typedef struct s_nb	t_nb;

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

void	e_pa(t_nb *stacks[2], size_t size[2]);
void	e_pb(t_nb *stacks[2], size_t size[2]);
void	e_sa(t_nb *stacks[2], size_t size[2]);
void	e_sb(t_nb *stacks[2], size_t size[2]);
void	e_ss(t_nb *stacks[2], size_t size[2]);
void	e_ra(t_nb *stacks[2], size_t size[2]);
void	e_rb(t_nb *stacks[2], size_t size[2]);
void	e_rr(t_nb *stacks[2], size_t size[2]);
void	e_rra(t_nb *stacks[2], size_t size[2]);
void	e_rrb(t_nb *stacks[2], size_t size[2]);
void	e_rrr(t_nb *stacks[2], size_t size[2]);

#endif
