/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:22:19 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/26 15:07:01 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_one_list(t_nb *stack)
{
	t_nb *start;

	start = stack;
	do
	{
		printf("|%.3d|\n", stack->nb);
		stack = stack->bellow;
	} while (start != stack);
	
}

void	print_list(t_nb	*stack[2], size_t size[2])
{
	size_t	ia, ib;

	ia = 0;
	ib = 0;
	while (ia < size[a] || ib < size[b])
	{
		if (ia < size[a])
		{
			fprintf(stderr, "|%.3d|",stack[a]->nb);
			stack[a] = stack[a]->bellow;
			++ia;
		}
		else
			fprintf(stderr, "|   |");
		if (ib < size[b])
		{
			fprintf(stderr, "%.3d|\n",stack[b]->nb);
			stack[b] = stack[b]->bellow;
			++ib;
		}
		else
			fprintf(stderr, "   |\n");
	}
}
