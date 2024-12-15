/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:15:32 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/12 09:58:16 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, t_const type)
{
	if (type == STACK_A)
	{
		log_fn("sa\n");
		int_swap(&a->arr[a->top], &a->arr[a->top - 1]);
	}
	else if (type == STACK_B)
	{
		log_fn("sb\n");
		int_swap(&b->arr[b->top], &b->arr[b->top - 1]);
	}
	else if (type == STACK_AB)
	{
		log_fn("ss\n");
		int_swap(&b->arr[b->top], &b->arr[b->top - 1]);
		int_swap(&a->arr[a->top], &a->arr[a->top - 1]);
	}
}

void	pp(t_stack *a, t_stack *b, t_const type)
{
	if (type == STACK_A)
	{
		log_fn("pa\n");
		if (is_empty(b) == FALSE)
		{
			push(a, peek(b));
			pop(b);
		}
	}
	else if (type == STACK_B)
	{
		log_fn("pb\n");
		if (is_empty(a) == FALSE)
		{
			push(b, peek(a));
			pop(a);
		}
	}
}

void	rr(t_stack	*a, t_stack *b, t_const type)
{
	if (type == STACK_A)
	{
		log_fn("ra\n");
		rotate(a);
	}
	else if (type == STACK_B)
	{
		log_fn("rb\n");
		rotate(b);
	}
	else if (type == STACK_AB)
	{
		log_fn("rr\n");
		rotate(a);
		rotate(b);
	}
}

void	rrr(t_stack *a, t_stack *b, t_const type)
{
	if (type == STACK_A)
	{
		log_fn("rra\n");
		rrotate(a);
	}
	else if (type == STACK_B)
	{
		log_fn("rrb\n");
		rrotate(a);
	}
	else if (type == STACK_AB)
	{
		log_fn("rrr\n");
		rrotate(a);
		rrotate(b);
	}
}

t_stack	*sort_stack(t_stack *s)
{
	t_stack	*tmp_s;
	int		tmp;

	tmp_s = init_stack();
	tmp_s->arr = malloc(sizeof(int) * s->top);
	push(tmp_s, pop(s));
	while (!is_empty(s))
	{
		tmp = pop(s);
		while (tmp >= peek(tmp_s) && !is_empty(tmp_s))
			push(s, pop(tmp_s));
		push(tmp_s, tmp);
	}
	free_stack(s);
	return (tmp_s);
}

t_stack	*sort_tri(t_stack *a, t_stack *b)
{
	int	t;
	int	*ar;

	t = a->top;
	ar = a->arr;
	if (t == 1)
		return (ss(a, b, STACK_A), a);
	if ((peek(a) < ar[t - 1] && ar[t - 1] > ar[t - 2] && peek(a) < ar[t - 2])
		|| (peek(a) > ar[t - 1] && ar[t - 1] < ar[t - 2] && peek(a) < ar[t - 2])
		|| (peek(a) > ar[t - 1] && ar[t - 1] > ar[t - 2] && peek(a) > ar[t - 2])
	)
		ss(a, b, STACK_A);
	// if (peek(a) < ar[t - 1] && ar[t - 1] > ar[t - 2] && peek(a) < ar[t - 2])
	// 	ss(a, b, STACK_A);
	// if (peek(a) > ar[t - 1] && ar[t - 1] > ar[t - 2] && peek(a) > ar[t - 2])
	// 	ss(a, b, STACK_A);
	// if (peek(a) > ar[t - 1] && ar[t - 1] < ar[t - 2] && peek(a) < ar[t - 2])
	// 	ss(a, b, STACK_A);
	if (peek(a) < ar[t - 1] && ar[t - 1] > ar[t - 2] && peek(a) > ar[t - 2])
		rrr(a, b, STACK_A);
	if (peek(a) > ar[t - 1] && ar[t - 1] < ar[t - 2] && peek(a) > ar[t - 2])
		rr(a, b, STACK_A);
	return (a);
}

t_stack	*sort_five(t_stack *a, t_stack *b)
{
	int	ops;

	while (a->top > 2)
	{
		ops = count_op(a, min_pos(a));
		if (ops < a->top)
			while (ops--)
				rr(a, b, STACK_A);
		else if (ops > a->top)
			while (ops-- > a->top)
				rrr(a, b, STACK_A);
		pp(a, b, STACK_B);
	}
	sort_tri(a, b);
	while (!is_empty(b))
		pp(a, b, STACK_A);
	return (a);
}

t_stack	*sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return (a);
	if (a->top <= 3)
		return (sort_tri(a, b));
	else if (a->top > 3 && a->top <= 5)
		return (sort_five(a, b));
	// else if (a->top > 5 && a->top <= 100)
	// 	return (sort_hunid(a, b));
	// else if (a->top > 100 && a->top <= 500)
	// 	return (sort_fhunid(a, b));
	// else
	// 	return (sort_biger(a, b));
	return (a);
}
