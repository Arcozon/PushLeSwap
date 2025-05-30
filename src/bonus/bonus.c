/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:08:19 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 13:21:14 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	e_order(t_nb *stacks[2], size_t size[2], t_order to_exec)
{
	static void	(*exec[NB_ORDER])(t_nb *[2], size_t [2]) = {e_pa, e_pb, e_sa,
		e_sb, e_ss, e_ra, e_rb, e_rr, e_rra, e_rrb, e_rrr};

	exec[to_exec](stacks, size);
}

void	print_error(char error[])
{
	write(2, error, ft_strlen(error));
}

char	checker_error(char errors, char *p_name)
{
	if (errors & E_MLLC)
	{
		print_error(p_name);
		print_error(": Malloc error\n");
	}
	else if (errors)
		print_error("Error\n");
	return (errors);
}

int	main(int ac, char *av[])
{
	t_checker	checker;

	if (ac == 1)
		return (0);
	if (!init_checker(&checker, av))
	{
	}
	free_stack(checker.stack[A], checker.size[A]);
	free_stack(checker.stack[B], checker.size[B]);
	return (checker_error(checker.errors, checker.p_name));
}
