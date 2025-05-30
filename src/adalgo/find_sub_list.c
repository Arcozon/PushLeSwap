/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sub_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:55:30 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:55:46 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rec_shit(t_nb *act, t_nb *start)
{
	t_nb	*tmp;

	tmp = start;
	act->lssl = 1;
	act->in_lssl = 0;
	act->to_swap = 0;
	while (tmp != act)
	{
		if (tmp->nb < act->nb && tmp->lssl >= act->lssl)
			act->lssl = tmp->lssl + 1;
		tmp = tmp->bellow;
	}
	if (act->bellow != start)
		rec_shit(act->bellow, start);
}

size_t	try_stuff(t_nb *a, size_t goal, t_nb *start, int itsok)
{
	if (itsok || a != start)
		goal = try_stuff(a->bellow, goal, start, 0);
	if (a == start)
		return (goal);
	if (a->lssl == goal)
	{
		a->in_lssl = 1;
		return (goal - 1);
	}
	a->in_lssl = 0;
	return (goal);
}

int	find_nb_in_lssl(t_nb *a, size_t goal)
{
	while (a)
	{
		if (a->lssl == goal && a->in_lssl)
			return (a->nb);
		a = a->bellow;
	}
	return (0);
}

int	try_shit(t_nb *act, size_t *goal_lssl, int biggest, t_nb *start)
{
	if (*goal_lssl == 0)
		return (0);
	if (!(act->lssl == *goal_lssl && act->in_lssl))
		biggest = try_shit(act->bellow, goal_lssl, biggest, start);
	if (act->lssl == *goal_lssl && act->in_lssl)
	{
		if (act != start && act->above->lssl == *goal_lssl
			&& act->above->nb < biggest && !act->above->to_swap)
		{
			act->to_swap = 1;
			act->above->to_swap = 1;
		}
		--*goal_lssl;
		return (act->nb);
	}
	return (biggest);
}

// A is just linked
void	find_sorted_list(t_nb *a)
{
	size_t	goal_lssl;

	rec_shit(a, a);
	goal_lssl = find_max_lssl(a)->lssl;
	try_stuff(a, goal_lssl, a, 1);
	try_shit(a, &goal_lssl, S_INT32_MAX, a);
}
