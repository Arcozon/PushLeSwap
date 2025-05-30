/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:21:18 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 13:14:41 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
