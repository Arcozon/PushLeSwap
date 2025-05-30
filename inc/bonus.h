/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeudes <gaeudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:08:38 by gaeudes           #+#    #+#             */
/*   Updated: 2025/05/30 13:15:45 by gaeudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define F_NOT_SORTED	0b1
# define A_NNUM			0b10
# define A_OVER			0b100
# define A_DBLE			0b1000
# define S_WRONG_INSTR	0b10000
# define E_MLLC			0b100000

# define NB_ORDER 11

enum
{
	A,
	B
};

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
	error
}	t_order;

typedef struct s_nb	t_nb;
struct s_nb
{
	int		nb;
	t_nb	*bellow;
	t_nb	*above;
};

typedef struct s_checker
{
	char	*p_name;

	t_nb	*stack[2];
	size_t	size[2];

	char	errors;
}	t_checker;

char	init_checker(t_checker *checker, char *av[]);

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
int		is_sorted(t_nb *stacks[2], size_t size[2]);

void	set_above(t_nb	*me, t_nb *above);
void	set_bellow(t_nb *me, t_nb *bellow);
t_nb	*insert_elem_above(t_nb	*to_insert, t_nb *bellow);
t_nb	*remove_elem(t_nb *to_remove);

char	check_doublon(t_nb *stack, size_t size);
char	are_they_formated_well(char *av[]);
int		fcked_atoi(int *ptr, char str[]);
int		ft_isdigit(char c);
void	free_stack(t_nb *stack, size_t size);

#endif
