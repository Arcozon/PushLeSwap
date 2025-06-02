/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:44 by gaeudes           #+#    #+#             */
/*   Updated: 2025/06/02 17:20:01 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

#define BELLOW 0
#define ABOVE 1

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
	static size_t	i = 0;
	t_nb			*goals[2];

	goals[BELLOW] = stack->above;
	goals[ABOVE] = stack;
	while (i < size)
	{
		while (stack != goals[BELLOW])
		{
			if (stack->nb == goals[BELLOW]->nb)
				return (A_DBLE);
			stack = stack->bellow;
		}
		goals[BELLOW] = (++i, stack->above);
		stack = stack->above;
		while (i < size && stack != goals[ABOVE])
		{
			if (stack->nb == goals[ABOVE]->nb)
				return (A_DBLE);
			stack = stack->above;
		}
		goals[ABOVE] = (++i, stack->bellow);
		stack = stack->bellow;
	}
	return (0);
}
