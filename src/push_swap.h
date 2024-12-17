/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:56:19 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/12 10:14:34 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

extern int op_count;

typedef struct s_stack
{
	int	*arr;
	int	top;
}	t_stack;

typedef enum
{
	FALSE,
	TRUE,
	STACK_A,
	STACK_B,
	STACK_AB,
	FORWARD,
	BACKWARD,
	ASCEND,
	DESCEND
} t_const;


/* Stack */
t_stack	*init_stack(void);
void	push(t_stack *s, int n);
int		pop(t_stack *s);
int		peek(t_stack *s);
void	free_stack(t_stack *s);
t_const	is_empty(t_stack *s);
void	print_stack(t_stack *s);

/* Parser*/
t_stack	*parse(int ac, char **av);

/* Sorting Algorithm */
t_stack	*sort_stack(t_stack *s);
t_stack	*sort(t_stack *a, t_stack *b);

/* Logging */
void	log_fn(char *name);

/* Utils */
void	int_swap(int *a, int *b);
t_stack	*rotate(t_stack *s);
t_stack	*rrotate(t_stack *s);
t_const	is_sorted(t_stack *s);
int		min_pos(t_stack *s);
int		max_pos(t_stack *s);
int		count_op(t_stack *s, int idx, t_const *direction);

#endif /* PUSH_SWAP_H */
