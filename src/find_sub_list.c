/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sub_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:55:30 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/28 18:23:34 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	debug_lssl(t_nb *a)
{
	const t_nb	*start = a;

	while (start != a->bellow)
	{
		printf("{%d}-%lu%s %s\n", a->nb, a->lssl, (char *[]){"    ", "  IN"}[a->in_lssl], (char *[]){"", "  SWAP"}[a->to_swap]);
		a = a->bellow;
	}
	printf("{%d}-%lu%s %s\n", a->nb, a->lssl, (char *[]){"    ", "  IN"}[a->in_lssl], (char *[]){"", "  SWAP"}[a->to_swap]);
}

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
	if (a->lssl == goal)
	{
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
	if (a->lssl >= m_lssl->lssl)
		m_lssl = a;
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

int	try_shit(t_nb *act, size_t *goal_lssl, int biggest)
{
	if (!(act->lssl == *goal_lssl && act->in_lssl))
		biggest = try_shit(act->bellow, goal_lssl, biggest);
	if (act->lssl == *goal_lssl && act->in_lssl)
	{
		// fprintf(stderr, "%d\n", biggest);
		if (act->above->lssl == *goal_lssl && act->above->nb < biggest)
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
	// debug_lssl(a);
	goal_lssl = find_max_lssl(a)->lssl;
	// printf("--%lu-\n", goal_lssl);
	try_stuff(a, goal_lssl, a, 1);
	// debug_lssl(a);
	try_shit(a, &goal_lssl, S_INT32_MAX);
	// printf("\n\n");
	// debug_lssl(a);
}
