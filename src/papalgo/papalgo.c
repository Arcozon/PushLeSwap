/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papalgo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:46:51 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/26 17:45:03 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

typedef struct s_papalgo
{
	size_t	isize_a;
	size_t	isize_b;

	size_t	*size;
	t_nb	**stack;

	size_t	group_size;
}	t_ppg;

static void	pp_eorders(t_ppg pp, t_order orders[], size_t max)
{
	while (*orders != end && max)
	{
		pe_order(pp.stack, pp.size, *orders);
		++orders;
		--max;
	}
}

static inline void	decrease(size_t *to_dec, size_t b)
{
	if (b > *to_dec)
		b = *to_dec;
	*to_dec -= b;
}

void	split_next_time(t_ppg pp)
{
	int		toggle_side;
	size_t	ia;
	size_t	ib;

	toggle_side = 0;
	while (pp.isize_a || pp.isize_b)
	{
		ia = pp.group_size;
		ib = pp.group_size;
		while (ia || ib)
		{
			if (toggle_side)
			{
				if (!ib || (ia && pp.stack[b]->nb > pp.stack[a]->nb))
					(--ia, pp_eorders(pp, (t_order []){pb, end}, 1));
				else
					--ib;
				pp_eorders(pp, (t_order []){rb, end}, 1);
			}
			else
			{
				if (!ia || (ib && pp.stack[b]->nb < pp.stack[a]->nb))
					(--ib, pp_eorders(pp, (t_order []){pa, end}, 1));
				else
					--ia;
				pp_eorders(pp, (t_order []){ra, end}, 1);
			}
		}
		decrease(&(pp.isize_a), pp.group_size);
		decrease(&(pp.isize_b), pp.group_size);
		toggle_side ^= 1;
	}
}

void	merge_last_time(t_ppg pp)
{
	size_t	ia;
	size_t	ib;

	ia = pp.size[a];
	ib = pp.size[b];
	while (ia || ib)
	{
		if (!ia || (ib && pp.stack[b]->nb < pp.stack[a]->nb))
			(--ib, pp_eorders(pp, (t_order []){pa, end}, 1));
		else
			--ia;
		pp_eorders(pp, (t_order []){ra, end}, 1);
	}
}

void	split_first_time(t_ppg pp)
{

	int	toggle_side;

	toggle_side = 0;
	while (pp.isize_a)
	{
		if (toggle_side)
		{
			if (pp.size[a] > 2 && pp.stack[a]->nb > pp.stack[a]->bellow->nb)
				pp_eorders(pp, (t_order[]){sa, end}, pp.isize_a);
			pp_eorders(pp, (t_order[]){ra, ra, end}, pp.isize_a);
		}
		else
		{
			if (pp.size[a] > 2 && pp.stack[a]->nb < pp.stack[a]->bellow->nb)
				pp_eorders(pp, (t_order[]){sa, end}, pp.isize_a);
			pp_eorders(pp, (t_order[]){pb, pb, end}, pp.isize_a);
		}
		decrease(&pp.isize_a, 2);
		toggle_side ^= 1;
	}
}

void	papalgo_init(t_nb *stack[2], size_t size[2])
{
	size_t size_total;
	t_ppg	pp;

	pp.stack = stack;
	pp.size = size;
	pp.group_size = 1;
	size_total = size[a];
	while (!is_sorted(stack, size) && pp.group_size < size_total)
	{
		pp.isize_a = size[a];
		pp.isize_b = size[b];
		if (pp.group_size == 1)
			split_first_time(pp);
		else if (pp.group_size * 2 >= size_total)
			merge_last_time(pp);
		else
			split_next_time(pp);
		pp.group_size *= 2;
	}
}
