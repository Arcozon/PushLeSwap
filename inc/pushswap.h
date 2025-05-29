/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:19:10 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/29 15:27:06 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "errors.h"
# include "force.h"

# define S_INT32_MIN -2147483648
# define S_INT32_MAX 2147483647
# define NB_ORDER 11

enum
{
	A,
	B
};

typedef struct s_nb	t_nb;
struct s_nb
{
	int		nb;
	t_nb	*bellow;
	t_nb	*above;

	size_t	lssl;
	int		in_lssl;
	unsigned char to_swap:1;
};
// len sub sorted list

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
void	find_sorted_list(t_nb *a);

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


void	e_order(t_nb *stacks[2], size_t size[2], t_order order);
void	p_order(t_order order);
void	pe_order(t_nb *stacks[2], size_t size[2], t_order order);

int		is_sorted(t_nb *stacks[2], size_t size[2]);

void	adalgo(t_nb *stacks[2], size_t size[2]);
void	push_all_poop(t_nb *stacks[2], size_t size[2]);

void	papalgo_init(t_nb *stack[2], size_t size[2]);

void	set_above(t_nb	*me, t_nb *above);
void	set_bellow(t_nb *me, t_nb *bellow);
t_nb	*insert_elem_above(t_nb	*to_insert, t_nb *bellow);
t_nb	*remove_elem(t_nb *to_remove);

int		slashchr(char *str);
int		ft_isdigit(char c);
size_t	ft_strlen(char str[]);
void	free_stack(t_nb *stack, size_t size);

// Debug
void	print_list(t_nb	*stack[2], size_t size[2]);
void	print_one_list(t_nb *stack);

#endif
#include <stdio.h>
