/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:47:44 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:03:59 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	insert_new(t_nb **a, int nb)
{
	t_nb	*new;

	new = malloc (sizeof(t_nb));
	if (!new)
		return (0);
	new->nb = nb;
	new->lssl = 0;
	new->bellow = 0;
	new->above = 0;
	while (*a)
		a = &((*a)->bellow);
	*a = new;
	return (1);
}

void	loop_stack(t_nb *a)
{
	t_nb	*start;

	if (!a)
		return ;
	start = a;
	while (a->bellow)
		a = a->bellow;
	a->bellow = start;
}

void	reverse_that_shit(t_nb *a)
{
	t_nb	*start;
	t_nb	*above;

	if (!a)
		return ;
	start = a;
	above = a;
	a = a->bellow;
	while (a != start)
	{
		a->above = above;
		above = a;
		a = a->bellow;
	}
	a->above = above;
}

char	fill_stacks(t_nb **a, size_t *size, char *av[])
{
	int	nb;

	while (*av)
	{
		if (!fcked_atoi(&nb, *av))
			return (A_OVER);
		if (!insert_new(a, nb))
			return (E_MLLC);
		++*size;
		++av;
	}
	loop_stack(*a);
	reverse_that_shit(*a);
	return (0);
}

char	init_ps(t_ps *ps, char *av[])
{
	ps->errors = are_they_formated_well(av + 1);
	ps->p_name = av[0];
	if (slashchr(av[0]) != -1)
		ps->p_name += slashchr(av[0]) + 1;
	ps->stack[A] = 0;
	ps->size[A] = 0;
	ps->stack[B] = 0;
	ps->size[B] = 0;
	if (!ps->errors)
		ps->errors |= fill_stacks(&(ps->stack[A]), &(ps->size[A]), av + 1);
	if (!ps->errors)
		ps->errors |= check_doublon(ps->stack[A], ps->size[A]);
	return (ps->errors);
}
