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
	op_count++;
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
	op_count++;
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
	op_count++;
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
	op_count++;
}

t_stack	*sort_stack(t_stack *s)
{
	t_stack	*tmp_s;
	int		tmp;

	tmp_s = init_stack();
	tmp_s->arr = malloc(sizeof(int) * (s->top + 1));
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

t_stack	*permutation_sort(t_stack *a, t_stack *b)
{
	int	t;
	int	*ar;

	t = a->top;
	ar = a->arr;
	if (t == 1)
		return (ss(a, b, STACK_A), a);
	if (peek(a) > ar[t - 1] && peek(a) > ar[t - 2])
		rr(a, b, STACK_A);
	else if (ar[t - 1] > peek(a) && ar[t - 1] > ar[t - 2])
		rrr(a, b, STACK_A);
	if (peek(a) > ar[t - 1])
		ss(a, b, STACK_A);
	return (a);
}

t_stack	*selection_sort(t_stack *a, t_stack *b)
{
	int		ops;
	t_const	direction;

	while (a->top > 2 && !is_sorted(a))
	{
		ops = count_op(a, min_pos(a), &direction);
		if (direction == FORWARD)
			while (ops-- > 0)
				rr(a, b, STACK_A);
		else if (direction == BACKWARD)
			while (ops-- > 0)
				rrr(a, b, STACK_A);
		pp(a, b, STACK_B);
	}
	if (!is_sorted(a))
		permutation_sort(a, b);
	while (!is_empty(b))
		pp(a, b, STACK_A);
	return (a);
}

t_stack	*sort_hunid(t_stack *a, t_stack *b)
{
	int		ops1;
	int		ops2;
	t_const	direction1;
	t_const	direction2;

	while (a->top > 2)
		pp(a, b, STACK_B);
	permutation_sort(a, b);
	while (b->top >= 0)
	{
		set_pref(a, b);
		ops1 = count_op(a, find_pos(b->target[b->pos_cheapest], a), &direction1);
		ops2 = count_op(b, b->pos_cheapest, &direction2);
		if (direction1 == direction2)
		{
			if (direction2 == FORWARD)
				while (ops1-- > 0 && ops2-- > 0)
					rr(a, b, STACK_AB);
			else if (direction1 == BACKWARD)
				while (ops1-- > 0 && ops2-- > 0)
					rrr(a, b, STACK_AB);
		}
		// if (find_pos(b->cheapest, b) > b->median
		// 	&& find_pos(b->target[find_pos(b->cheapest, b)], a) > a->median)
		// {
		// 	while (peek(a) != b->target[find_pos(b->cheapest, b)] && peek(b) != b->cheapest)
		// 	{
		// 		rrr(a, b, STACK_AB);
		// 		set_target(a, b);
		// 	}
		// }
		// else if (find_pos(b->cheapest, b) < b->median
		// 	&& find_pos(b->target[find_pos(b->cheapest, b)], a) < a->median)
		// {
		// 	while (peek(a) != b->target[find_pos(b->cheapest, b)] && peek(b) != b->cheapest)
		// 	{
		// 		rr(a, b, STACK_AB);
		// 		set_target(a, b);
		// 	}
		// }
		// ops1 = count_op(a, find_pos(b->target[find_pos(b->cheapest, b)], a), &direction1);
		if (direction1 == FORWARD && ops1 > 0)
			while (ops1-- > 0)
				rr(a, b, STACK_A);
		else if (direction1 == BACKWARD)
			while (ops1-- > 0)
				rrr(a, b, STACK_A);
		// ops2 = count_op(b, find_pos(b->cheapest, b), &direction2);
		if (direction2 == FORWARD && ops2 > 0)
			while (ops2-- > 0)
				rr(a, b, STACK_B);
		else if (direction2 == BACKWARD)
			while (ops2-- > 0)
				rrr(a, b, STACK_B);
		// while (peek(b) != b->cheapest)
		// {
		// 	if (find_pos(b->cheapest, b) > b->median)
		// 		rrr(a, b, STACK_B);
		// 	else
		// 		rr(a, b, STACK_B);
		// 	set_target(a, b);
		// }
		// while (peek(a) != b->target[find_pos(b->cheapest, b)])
		// {
		// 	if (find_pos(b->target[find_pos(b->cheapest, b)], a) > a->median)
		// 		rrr(a, b, STACK_A);
		// 	else
		// 		rr(a, b, STACK_A);
		// 	set_target(a, b);
		// }
		pp(a, b, STACK_A);
	}
	ops1 = count_op(a, min_pos(a), &direction1);
	if (direction1 == FORWARD)
		while (ops1-- > 0)
			rr(a, b, STACK_A);
	else if (direction1 == BACKWARD)
		while (ops1-- > 0)
			rrr(a, b, STACK_A);
	return (a);
}

t_stack	*sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return (a);
	if (a->top < 3)
		return (permutation_sort(a, b));
	else if (a->top >= 3 && a->top < 15)
		return (selection_sort(a, b));
	else if (a->top > 15 && a->top <= 500)
		return (sort_hunid(a, b));
	return (a);
}
