/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sub_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:55:30 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/28 15:36:39 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	debug_lssl(t_nb *a)
{
	const t_nb	*start = a;

	while (start != a->bellow)
	{
		printf("{%d}-%lu%s\n", a->nb, a->lssl, (char *[]){"", "  IN"}[a->in_lssl]);
		a = a->bellow;
	}
}

void	rec_shit(t_nb *act, t_nb *start)
{
	t_nb	*tmp;

	tmp = start;
	act->lssl = 1;
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

size_t	try_stuff(t_nb *a, size_t goal, t_nb *start)
{
	if (a->bellow != start)
		goal = try_stuff(a->bellow, goal, start);
	if (a->lssl == goal)
	{
		printf("+%d+\n", a->nb);
		a->in_lssl = 1;
		return (goal - 1);
	}
	a->in_lssl = 0;
	return (goal);
}

t_nb	*find_max_lssl(t_nb *a)
{
	const t_nb	*start = a;
	t_nb		*m_lssl;

	m_lssl = a;
	while (start->above != a)
	{
		if (a->lssl >= m_lssl->lssl)
			m_lssl = a;
		a = a->bellow;
	}
	return (m_lssl);
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


// A is just linked
void	find_sorted_list(t_nb *a)
{
	rec_shit(a, a);
	// debug_lssl(a);
	try_stuff(a, find_max_lssl(a)->lssl, a);
	debug_lssl(a);
}
