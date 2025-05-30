/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:47:44 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 13:08:13 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	insert_new(t_nb **a, int nb)
{
	t_nb	*new;

	new = malloc (sizeof(t_nb));
	if (!new)
		return (0);
	new->nb = nb;
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

char	fill_stacks(t_nb **a, size_t* size, char *av[])
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

char	init_checker(t_checker *checker, char *av[])
{
	checker->errors = are_they_formated_well(av + 1);
	checker->p_name = av[0];
	if (slashchr(av[0]) != -1)
		checker->p_name += slashchr(av[0]) + 1;
	checker->stack[A] = 0;
	checker->size[A] = 0;
	checker->stack[B] = 0;
	checker->size[B] = 0;
	if (!checker->errors)
		checker->errors |= fill_stacks(&(checker->stack[A]),
			&(checker->size[A]), av + 1);
	if (!checker->errors)
		checker->errors |= check_doublon(checker->stack[A], checker->size[A]);
	return (checker->errors);
}
