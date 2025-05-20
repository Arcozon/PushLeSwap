/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:19:10 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/20 19:48:10 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "errors.h"

enum
{
	a,
	b
};

typedef struct s_pile
{
	int		*pile;
	size_t	top;

	size_t	size;
}	t_pile;


typedef struct s_pushswap
{
	char	*p_name;

	t_pile	piles[2];

	char	errors;
}	t_ps;

int	are_they_formated_well(char *av[]);
int	fcked_atoi(int *ptr, char str[]);

int slashchr(char *str);
int	ft_isdigit(char c);
size_t	ft_strlen(char str[]);

#endif
#include <stdio.h>
