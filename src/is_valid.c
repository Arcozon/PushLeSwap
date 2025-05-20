/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:44 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/20 19:17:27 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_he_formated_well(char str[])
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		++i;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

int	are_they_formated_well(char *av[])
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (!is_he_formated_well(av[i]))
			return (A_NNUM);
		++i;
	}
	return (0);
}

int	fcked_atoi(int *ptr, char str[])
{
	long	res;
	int		sign;
	size_t	i;

	sign = 1;
	res = 0;
	if (str[i] == '-')
		sign = (++i, -1);
	while (ft_isdigit(str[i]))
	{
		res += 10 * res + str[i] - '0';
		if (res > (2147483647 + (sign == -1)))
			return (0);
		++i;
	}
	*ptr = res;
	return (str[i] == 0);
}
