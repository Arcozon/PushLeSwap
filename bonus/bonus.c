/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:08:19 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 17:08:33 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	print_error(char error[])
{
	write(2, error, ft_strlen(error));
}

void	checker_error(char errors, char *p_name)
{
	if (errors & E_MLLC)
	{
		print_error(p_name);
		print_error(": Malloc error\n");
	}
	else if (errors)
		print_error("Error\n");
}

void	checker_routine(t_checker *checker)
{
	t_order	order;

	order = 0;
	fix_them(checker->stack[A], checker->size[A]);
	while (order != done)
	{
		order = get_next_order();
		if (order == error)
		{
			checker->errors |= S_WRONG_INSTR;
			return ;
		}
		else if (order != done)
			e_order(checker->stack, checker->size, order);
	}
	if (!is_sorted(checker->stack, checker->size))
		checker->errors |= F_NOT_SORTED;
}

int	main(int ac, char *av[])
{
	t_checker	checker;

	if (ac == 1)
		return (0);
	if (!init_checker(&checker, av))
		checker_routine(&checker);
	free_stack(checker.stack[A], checker.size[A]);
	free_stack(checker.stack[B], checker.size[B]);
	checker_error(checker.errors & ~F_NOT_SORTED, checker.p_name);
	if (!(checker.errors & ~F_NOT_SORTED))
		write(1, (char *[]){"OK\n", "KO\n"}[checker.errors & F_NOT_SORTED], 3);
	return (checker.errors);
}
