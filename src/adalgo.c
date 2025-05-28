/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adalgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:24:35 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/28 18:28:50 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_all_poop(t_nb *stacks[2], size_t size[2])
{
	size_t	len = size[a];

	while (len--)
	{
		if (stacks[a]->to_swap)
		{
			pe_order(stacks, size, sa);
			pe_order(stacks, size, ra);
			pe_order(stacks, size, ra);
			--len;
		}
		else if (stacks[a]->in_lssl)
			pe_order(stacks, size, ra);
		else
			pe_order(stacks, size, pb);
	}
}
