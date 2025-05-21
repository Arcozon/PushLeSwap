/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_them.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:26:21 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/21 15:52:53 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	apply_delta(t_nb *stack, size_t size, int delta)
{
	while (size--)
	{
		stack->nb -= delta;
		stack = stack->above;
	}
}

int	get_delta(t_nb *stack, size_t size)
{
	int	min;

	min = stack->nb;
	while (--size)
	{
		stack = stack->bellow;
		if (stack->nb < min)
			min = stack->nb;
	}
	return (min - S_INT32_MIN);
}

int	fix_next_biggest(int last_big, t_nb *stack, size_t size, int i)
{
	t_nb	*to_fix;

	while (--size)
	{
		if (stack->nb > last_big && stack->nb < to_fix->nb)
			to_fix = stack;
		stack = stack->above;
	}
	to_fix->nb = S_INT32_MIN + i;
}
void	allign_them(t_nb *stack)
{
	
}

void	fix_them(t_nb *stack, size_t size)
{
	apply_delta(stack, size, get_delta(stack, size));
}
