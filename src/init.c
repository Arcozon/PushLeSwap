/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:47:44 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/20 19:42:38 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	init_pile(t_pile piles[2], int ac)
{
	piles[a].top = 0;
	piles[a].size = ac;
	piles[b].top = 0;
	piles[b].size = 0;
	piles[a].pile = malloc(sizeof(int) * ac);
	piles[b].pile = malloc(sizeof(int) * ac);
	if (!piles[a].pile || !piles[b].pile)
	{
		free(piles[a].pile);
		free(piles[b].pile);
		return (E_MLLC);
	}
	return (0);
}

char	check_pair(int *pile, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (pile[i] == pile[j])
				return (A_DBLE);
			++j;
		}
		++i;
	}
	return (0);
}

void	fill_piles(t_pile piles[2], t_ps *ps, int ac, char *av[])
{
	int	i;

	ps->errors |= init_pile(piles, ac);\
	if (ps->errors)
		return ;
	i = 0;
	while (i < ac)
	{
		if (!fcked_atoi(&(piles[a].pile[i]), av[i]))
		{
			ps->errors |= A_OVER;
			free(piles[a].pile);
			free(piles[b].pile);
			return ;
		}
		++i;
	}
	ps->errors |= check_pair(piles[1].pile, ac);
	if (ps->errors)
	{
		free(piles[a].pile);
		free(piles[b].pile);
	}
}

int	init_ps(t_ps *ps, int ac, char *av[])
{
	ps->errors = are_args_valid(ac, av);
	ps->p_name = av[0];
	if (!ps->errors)
		fill_piles(ps->piles, ps, ac - 1, av + 1);
	return (ps->errors);
}
