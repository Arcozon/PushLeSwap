/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ada_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:24:35 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:31:20 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	init_best(t_bmove *bmove)
{
	bmove->n_rr = 0;
	bmove->n_ra = 0;
	bmove->n_rb = 0;
	bmove->n_rra = 0;
	bmove->n_rrb = 0;
	bmove->n_rrr = 0;
	bmove->n_tt = 0;
}

t_nb	*max_of_stack(t_nb *stack)
{
	const t_nb	*start = stack;
	t_nb		*max;

	max = stack;
	stack = stack->above;
	while (stack != start)
	{
		if (stack->nb > max->nb)
			max = stack;
		stack = stack->above;
	}
	return (max);
}

t_nb	*min_of_stack(t_nb *stack)
{
	const t_nb	*start = stack;
	t_nb		*min;

	min = stack;
	stack = stack->above;
	while (stack != start)
	{
		if (stack->nb < min->nb)
			min = stack;
		stack = stack->above;
	}
	return (min);
}

size_t	get_distance_0(t_nb *stack)
{
	size_t	distance;

	distance = 0;
	while (1)
	{
		if (stack->nb == 0)
			return (distance);
		++distance;
		stack = stack->bellow;
	}
}
