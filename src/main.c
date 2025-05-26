/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:20:17 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/26 15:59:39 by gaeudes          ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	t_ps	ps;

	if (ac == 1)
		return (0);
	if (!init_ps(&ps, av))
	{
		fix_them(ps.stack[a], ps.size[a]);
		print_list(ps.stack, ps.size);
		// if (ps.size[a] <= 10)
		// 	start_brutforce(ps.stack, ps.size);
		// else
			papalgo_init(ps.stack, ps.size);
		print_list(ps.stack, ps.size);
	}
	free_stack(ps.stack[a], ps.size[a]);
	return (ps_error(ps.errors, ps.p_name));
	(void)ac;
}
