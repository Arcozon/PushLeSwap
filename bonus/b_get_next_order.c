/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_get_next_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:35:59 by gaeudes           #+#    #+#             */
/*   Updated: 2025/06/04 15:18:19 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	is_in_order_empty(char *in_order)
{
	int	i;

	i = -1;
	while (++i < NB_ORDER)
		if (in_order[i])
			return (0);
	return (1);
}

void	fill_in_order(char *in_order)
{
	int	i;

	i = 0;
	while (i < NB_ORDER)
	{
		in_order[i] = 1;
		++i;
	}
}

t_order	get_order(char *in_order, int j)
{
	static const char	*orders[] = {"pa", "pb", "sa", "sb", "ss", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};
	int					i;

	i = 0;
	while (i < NB_ORDER)
	{
		if (in_order[i] && !orders[i][j])
			return (i);
		++i;
	}
	return (error);
}

void	update_in_order(int j, char *in_order, char c)
{
	static const char	*orders[] = {"pa", "pb", "sa", "sb", "ss", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};
	int					i;

	i = -1;
	while (++i < NB_ORDER)
		if (c != orders[i][j])
			in_order[i] = 0;
}

void	empty_stdin()
{
	char	c;
	int		br;

	br = read(0, &c, 1);
	while (br == 1 && c != '\n')
		br = read(0, &c, 1);
}

t_order	get_next_order(void)
{
	char	in_order[NB_ORDER];
	char	c;
	int		br;
	int		j;

	fill_in_order(in_order);
	br = read(0, &c, 1);
	if (br == 0)
		return (done);
	j = 0;
	while (br > 0 && !is_in_order_empty(in_order))
	{
		if (c == '\n')
			break ;
		if (br)
			update_in_order(j, in_order, c);
		++j;
		br = read(0, &c, 1);
	}
	if (br < 0)
		return (error);
	if (is_in_order_empty(in_order))
		while (br == 1 && c != '\n')
		br = read(0, &c, 1);
	return (get_order(in_order, j));
}
