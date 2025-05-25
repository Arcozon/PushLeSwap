/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_order1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:42:03 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/25 17:20:12 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	e_sa(t_nb *stacks[2], size_t size[2])
{
	int	swap;

	if (size[a] < 2)
		return ;
	swap = stacks[a]->nb;
	stacks[a]->nb = stacks[a]->bellow->nb;
	stacks[a]->bellow->nb = swap;
}

void	e_sb(t_nb *stacks[2], size_t size[2])
{
	int	swap;

	if (size[b] < 2)
		return ;
	swap = stacks[b]->nb;
	stacks[b]->nb = stacks[b]->bellow->nb;
	stacks[b]->bellow->nb = swap;
}

void	e_ss(t_nb *stacks[2], size_t size[2])
{
	e_sa(stacks, size);
	e_sb(stacks, size);
}

void	e_pa(t_nb *stacks[2], size_t size[2])
{
	t_nb	*swap;

	if (!size[b])
		return ;
	swap = stacks[b];
	stacks[b] = remove_elem(stacks[b]);
	--size[b];
	stacks[a] = insert_elem_above(swap, stacks[a]);
	++size[a];
}

void	e_pb(t_nb *stacks[2], size_t size[2])
{
	t_nb	*swap;

	if (!size[a])
		return ;
	swap = stacks[a];
	stacks[a] = remove_elem(stacks[a]);
	--size[a];
	stacks[b] = insert_elem_above(swap, stacks[b]);
	++size[b];
}
