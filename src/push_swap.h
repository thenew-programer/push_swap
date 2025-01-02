/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:28:58 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/01 08:40:09 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

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
	int				price;
	int				pos;
	t_const			below_avg;
	t_const			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

/* Stack impl and utility functions */
t_stack	*stacknew(int data);
void	stackadd_front(t_stack **head, t_stack *new_node);
int		stacksize(t_stack *s);
void	stackfree(t_stack **s);
t_stack	*stacklast(t_stack *s);
t_stack	*stackfind(t_stack *s, int data);
t_stack	*stackget(t_stack *s, int idx);
void	stackpos(t_stack *s);
int		pop(t_stack **s);
int		push(t_stack **s, int data);

/* Command Utils */
void	swap_node(t_stack **s);
void	rotate(t_stack **s);
void	rrotate(t_stack **s);
t_const	is_sorted(t_stack *s);
t_stack	*min_node(t_stack *s);
void	set_target(t_stack *a, t_stack *b);
void	set_price(t_stack *a, t_stack *b);
t_stack	*set_cheapest(t_stack *b);
t_const	is_space(char c);

/* Parser functions */
t_stack	*parser(int ac, char **av);
char	**parse_av(int *ac, char *str);
void	free_av(char **av);

/* Commands */
void	ss(t_stack **a, t_stack **b, t_const flag);
void	rr(t_stack **a, t_stack **b, t_const flag);
void	rrr(t_stack **a, t_stack **b, t_const flag);
void	pp(t_stack **a, t_stack **b, t_const flag);

/* Push Swap algorithm */
void	light_sort(t_stack **a, t_stack **b);
void	mid_sort(t_stack **a, t_stack **b);
void	move_cheapest_to_a(t_stack **a, t_stack **b, t_stack *cheapest);
void	heavy_sort(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);

/* Error handling function */
void	input_error(t_stack **s, t_const msg);

#endif /* PUSH_SWAP_H */
