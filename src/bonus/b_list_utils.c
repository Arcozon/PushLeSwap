/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:26:52 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:00:44 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	set_above(t_nb	*me, t_nb *above)
{
	me->above = above;
	above->bellow = me;
}

void	set_bellow(t_nb *me, t_nb *bellow)
{
	me->bellow = bellow;
	bellow->above = me;
}

t_nb	*insert_elem_above(t_nb	*to_insert, t_nb *bellow)
{
	t_nb	*above;

	if (!to_insert)
		return (bellow);
	if (!bellow)
		set_bellow(to_insert, to_insert);
	else
	{
		above = bellow->above;
		set_above(to_insert, above);
		set_bellow(to_insert, bellow);
	}
	return (to_insert);
}

t_nb	*remove_elem(t_nb *to_remove)
{
	t_nb	*bellow;

	if (!to_remove || to_remove->above == to_remove)
		return (0);
	bellow = to_remove->bellow;
	set_above(bellow, to_remove->above);
	set_above(to_remove, to_remove);
	return (bellow);
}

int	is_sorted(t_nb *stacks[2], size_t size[2])
{
	size_t	size_a;
	t_nb	*stack_a;
	int		expected;

	if (size[B])
		return (0);
	expected = 0;
	size_a = size[A];
	stack_a = stacks[A];
	while (size_a--)
	{
		if (stack_a->nb != expected)
			return (0);
		stack_a = stack_a->bellow;
		++expected;
	}
	return (1);
}
