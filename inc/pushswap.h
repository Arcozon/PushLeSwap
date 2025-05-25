/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:19:10 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/25 16:35:54 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "errors.h"

# define S_INT32_MIN -2147483648

enum
{
	a,
	b
};

typedef struct s_nb	t_nb;
struct s_nb
{
	int		nb;
	t_nb	*bellow;
	t_nb	*above;	
};

typedef struct s_pushswap
{
	char	*p_name;

	t_nb	*stack[2];
	size_t	size[2];

	char	errors;
}	t_ps;

char	init_ps(t_ps *ps, char *av[]);

char	check_doublon(t_nb *stack, size_t size);
char	are_they_formated_well(char *av[]);
int		fcked_atoi(int *ptr, char str[]);
void	fix_them(t_nb *stack, size_t size);

int		slashchr(char *str);
int		ft_isdigit(char c);
size_t	ft_strlen(char str[]);
void	free_stack(t_nb *stack, size_t size);

// Debug
void	print_list(t_nb	*stack[2], size_t size[2]);
void	print_one_list(t_nb *stack);

#endif
#include <stdio.h>
