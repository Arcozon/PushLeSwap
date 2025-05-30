/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exec_s_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:42:03 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 15:57:18 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	e_sa(t_nb *stacks[2], size_t size[2])
{
	int	swap;

	if (size[A] < 2)
		return ;
	swap = stacks[A]->nb;
	stacks[A]->nb = stacks[A]->bellow->nb;
	stacks[A]->bellow->nb = swap;
}

void	e_sb(t_nb *stacks[2], size_t size[2])
{
	int	swap;

	if (size[B] < 2)
		return ;
	swap = stacks[B]->nb;
	stacks[B]->nb = stacks[B]->bellow->nb;
	stacks[B]->bellow->nb = swap;
}

void	e_ss(t_nb *stacks[2], size_t size[2])
{
	e_sa(stacks, size);
	e_sb(stacks, size);
}

void	e_pa(t_nb *stacks[2], size_t size[2])
{
	t_nb	*swap;

	if (!size[B])
		return ;
	swap = stacks[B];
	stacks[B] = remove_elem(stacks[B]);
	--size[B];
	stacks[A] = insert_elem_above(swap, stacks[A]);
	++size[A];
}

void	e_pb(t_nb *stacks[2], size_t size[2])
{
	t_nb	*swap;

	if (!size[A])
		return ;
	swap = stacks[A];
	stacks[A] = remove_elem(stacks[A]);
	--size[A];
	stacks[B] = insert_elem_above(swap, stacks[B]);
	++size[B];
}
