/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:44 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/21 14:22:04 by gaeudes          ###   ########.fr       */
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

char	check_doublon(t_nb *stack, size_t size)
{
	size_t	i;
	t_nb	*goal_bellow;
	t_nb	*goal_above;

	i = 0;
	goal_bellow = stack->above;
	goal_above = stack->bellow;
	while (i < size)
	{
		while (stack != goal_bellow)
		{
			if (stack->nb == goal_bellow->nb)
				return (A_DBLE);
			stack = stack->bellow;
		}
		goal_bellow = (++i, stack->above);
		while (stack != goal_above)
		{
			if (stack->nb == goal_above->nb)
				return (A_DBLE);
			stack = stack->above;
		}
		goal_above = (++i, stack->bellow);
	}
	return (0);
}
