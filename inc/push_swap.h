/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:28:58 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/31 19:25:10 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"

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
	bool			below_avg;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

/*
 * t_const:		enum to handle states for commands
 *
 * @STACK_A:	means the function should work on stack a
 * @STACK_B:	means the function should work on stack b
 * @STACK_AB:	means the function should work on stack a and b
 * */
typedef enum
{
	STACK_A,
	STACK_B,
	STACK_AB,
}	t_const;

/* Stack impl and utility functions */
t_stack	*stknew(int data);
void	stkadd_front(t_stack **head, t_stack *new_node);
int		stksize(t_stack *head);
void	stkfree(t_stack **head);
void	stkprint(t_stack *head);
t_stack	*stklast(t_stack *head);
int		pop(t_stack **head);
void	push(t_stack **head, int data);

/* Command Utils */
void	swap_node(t_stack **s);
void	rotate(t_stack **s);
void	rrotate(t_stack **s);

#endif /* PUSH_SWAP_H */
