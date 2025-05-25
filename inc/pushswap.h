/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:19:10 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/25 19:31:49 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "errors.h"

# define S_INT32_MIN -2147483648

# define MAX_DEPTH 17 

# define NB_ORDER 11

typedef enum e_order
{
	pa,
	pb,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	end
}	t_order;

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

int		start_brut_force(t_nb *stacks[2], size_t size[2]);

void	e_pa(t_nb *stacks[2], size_t size[2]);
void	e_pb(t_nb *stacks[2], size_t size[2]);
void	e_sa(t_nb *stacks[2], size_t size[2]);
void	e_sb(t_nb *stacks[2], size_t size[2]);
void	e_ss(t_nb *stacks[2], size_t size[2]);

void	e_ra(t_nb *stacks[2], size_t size[2]);
void	e_rb(t_nb *stacks[2], size_t size[2]);
void	e_rr(t_nb *stacks[2], size_t size[2]);
void	e_rra(t_nb *stacks[2], size_t size[2]);
void	e_rrb(t_nb *stacks[2], size_t size[2]);
void	e_rrr(t_nb *stacks[2], size_t size[2]);

int		is_sorted(t_nb *stacks[2], size_t size[2]);

void	set_above(t_nb	*me, t_nb *above);
void	set_bellow(t_nb *me, t_nb *bellow);
t_nb	*insert_elem_above(t_nb	*to_insert, t_nb *bellow);
t_nb	*remove_elem(t_nb *to_remove);

int		slashchr(char *str);
int		ft_isdigit(char c);
size_t	ft_strlen(char str[]);
void	free_stack(t_nb *stack, size_t size);

void	print_one_order(t_order order);
// Debug

void	print_list(t_nb	*stack[2], size_t size[2]);
void	print_one_list(t_nb *stack);

#endif
#include <stdio.h>
