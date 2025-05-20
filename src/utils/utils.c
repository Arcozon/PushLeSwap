/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:24:56 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/20 19:47:22 by gaeudes          ###   ########.fr       */
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
	reutrn (c >= '0' && c <= '9');
}

size_t ft_strlen(char str[])
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
