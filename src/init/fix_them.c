/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_them.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:26:21 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/25 19:21:45 by gaeudes          ###   ########.fr       */
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

void	fix_next_biggest(int last_big, t_nb *stack, size_t size, int i)
{
	t_nb	*to_fix;

	to_fix = 0;
	while (size--)
	{
		if (stack->nb > last_big && (!to_fix || to_fix->nb > stack->nb))
		{
			to_fix = stack;
		}
		stack = stack->bellow;
	}
	if (to_fix)
		to_fix->nb = S_INT32_MIN + i;
}

void	align_them(t_nb *stack, size_t size)
{
	size_t	i;
	int		target;

	i = size;
	target = 0;
	while (i-- > 1)
	{
		fix_next_biggest(S_INT32_MIN + target, stack, size, target + 1);
		++target;
	}
}

void	fix_them(t_nb *stack, size_t size)
{
	apply_delta(stack, size, get_delta(stack, size));
	// print_one_list(stack);
	align_them(stack, size);
	// printf("---------------------\n");
	// print_one_list(stack);
	apply_delta(stack, size, S_INT32_MIN);
	// printf("---------------------\n");
	// print_one_list(stack);
}
