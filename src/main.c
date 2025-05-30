/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:20:17 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 16:58:51 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_error(char error[])
{
	write(2, error, ft_strlen(error));
}

char	ps_error(char errors, char *p_name)
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

// CHECK SEGFAULT
int	main(int ac, char *av[])
{
	t_ps	ps;

	if (ac == 1)
		return (0);
	if (!init_ps(&ps, av))
	{
		fix_them(ps.stack[A], ps.size[A]);
		if (ps.size[A] <= 8)
			start_brutforce(ps.stack, ps.size);
		else
			adalgo(ps.stack, ps.size);
	}
	free_stack(ps.stack[A], ps.size[A]);
	return (ps_error(ps.errors, ps.p_name));
}
