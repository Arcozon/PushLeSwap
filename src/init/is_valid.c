/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:44 by gaeudes           #+#    #+#             */
/*   Updated: 2025/06/02 15:28:30 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_he_formated_well(char str[])
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		++i;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

char	are_they_formated_well(char *av[])
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (!is_he_formated_well(av[i]))
			return (A_NNUM);
		++i;
	}
	return (0);
}
#include <stdio.h>
char	check_doublon(t_nb *stack, size_t size)
{
	size_t	i;
	t_nb	*goal_bellow;
	t_nb	*goal_above;

	i = 0;
	goal_bellow = stack;
	goal_above = stack->bellow;
	stack = stack->bellow;
	while (i < size)
	{
		fprintf(stderr, "BELLOW: %10p :% 2d\n", goal_bellow, goal_bellow->nb);
		while (stack != goal_bellow)
		{
			fprintf(stderr, "-- %10p :% 2d\n", stack, stack->nb);
			if (stack->nb == goal_bellow->nb)
				return (A_DBLE);
			stack = stack->bellow;
		}
		goal_bellow = (++i, stack->above);
		fprintf(stderr, "ABOVE: %10p :% 2d\n", goal_above, goal_above->nb);
		stack = stack->above;
		while (i < size && stack != goal_above)
		{
			fprintf(stderr, "-- %10p :% 2d\n", stack, stack->nb);
			if (stack->nb == goal_above->nb)
				return (A_DBLE);
			stack = stack->above;
		}
		goal_above = (++i, stack->bellow);
		stack = stack->bellow;
	}
	return (0);
}
