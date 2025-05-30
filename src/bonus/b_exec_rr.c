/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:21:26 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/29 15:24:19 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	e_rra(t_nb *stacks[2], size_t size[2])
{
	if (!size[A])
		return ;
	stacks[A] = stacks[A]->above;
}

void	e_rrb(t_nb *stacks[2], size_t size[2])
{
	if (!size[B])
		return ;
	stacks[B] = stacks[B]->above;
}

void	e_rrr(t_nb *stacks[2], size_t size[2])
{
	e_rra(stacks, size);
	e_rrb(stacks, size);
}
