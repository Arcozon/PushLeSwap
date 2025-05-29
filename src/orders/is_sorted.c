/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:48:39 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/29 15:24:56 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
