/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:09:28 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/28 11:47:26 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/*
 * t_const:		enum to handle states for commands
 *
 * @STACK_A:	means the function should work on stack a
 * @STACK_B:	means the function should work on stack b
 * @STACK_AB:	means the function should work on stack a and b
 * */
typedef enum e_const
{
	FALSE,
	TRUE,
	STACK_A,
	STACK_B,
	STACK_AB,
}	t_const;

/*
 * t_stack:		stack impl with linked lists
 * @data:		number
 * @price:		number of operation to get node to top
 * @below_avg:	is node is below avg
 * @next:		next node
 * @prev:		previous node
 * @target:		target node, each element in a stack a, will have
 * 				a target node in stack b, or the inverse.
 * */
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

/*
 * t_ops:		struct to encapsulate the function and there operations.
 *
 * @op:			Operation name.
 * @f			Operation handler function.
 * */
typedef struct s_ops
{
	char	*op;
	void	(*f)(t_stack **, t_stack **, t_const);
}	t_ops;

/* Stack impl and utility functions */
t_stack	*stacknew(int data);
void	stackadd_front(t_stack **head, t_stack *new_node);
int		stacksize(t_stack *head);
void	stackfree(t_stack **head);
t_stack	*stacklast(t_stack *head);
t_stack	*stackfind(t_stack *head, int data);
t_stack	*stackget(t_stack *head, int idx);
void	stackpos(t_stack *s);
int		pop(t_stack **head);
int		push(t_stack **head, int data);

/* Command Utils */
void	swap_node(t_stack **s);
void	rotate(t_stack **s);
void	rrotate(t_stack **s);
t_const	is_sorted(t_stack *s);
t_const	is_space(char c);

/* Parser functions */
t_stack	*parser(int ac, char **av);
char	**parse_av(int *ac, char *str);
void	free_av(char **av);
char	**parse_ops(char *s);

/* Commands */
void	ss(t_stack **a, t_stack **b, t_const flag);
void	rr(t_stack **a, t_stack **b, t_const flag);
void	rrr(t_stack **a, t_stack **b, t_const flag);
void	pp(t_stack **a, t_stack **b, t_const flag);

/* Error handling function */
void	input_error(t_stack **s, t_const msg);

/* Sorting functions */
int		sort(t_stack **a, t_stack **b, int a_size);

#endif /* PUSH_SWAP_H */
