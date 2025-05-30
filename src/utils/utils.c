/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:24:56 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 17:12:05 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	slashchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (i);
		++i;
	}
	return (-1);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(char str[])
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	fcked_atoi(int *ptr, char str[])
{
	long	res;
	int		sign;
	size_t	i;

	sign = 1;
	res = 0;
	i = 0;
	if (str[i] == '-')
		sign = (++i, -1);
	while (ft_isdigit(str[i]))
	{
		res = 10 * res + str[i] - '0';
		if (res > (2147483647L + (sign == -1)))
			return (0);
		++i;
	}
	*ptr = res * sign;
	return (str[i] == 0);
}

void	free_stack(t_nb *stack, size_t size)
{
	t_nb	*to_free;

	while (size--)
	{
		to_free = stack;
		stack = stack->above;
		free(to_free);
	}
}
