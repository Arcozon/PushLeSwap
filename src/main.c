/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:20:17 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/20 19:50:56 by gaeudes          ###   ########.fr       */
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
}

int	main(int ac, char *av[])
{
	t_ps	ps;

	if (init_ps(&ps, ac, av))
	{
		// Core
	}
	return (ps_error(ps.errors));
}
