/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 08:36:26 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/01 08:41:07 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	light_sort(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->data > stackget(*a, 1)->data
		&& (*a)->data > stackget(*a, 2)->data)
		rr(a, b, STACK_A);
	else if (stackget(*a, 1)->data > (*a)->data
		&& stackget(*a, 1)->data > stackget(*a, 2)->data)
		rrr(a, b, STACK_A);
	if ((*a)->data > stackget(*a, 1)->data)
		ss(a, b, STACK_A);
}

void	mid_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;

	if (is_sorted(*a))
		return ;
	while (stacksize(*a) > 3)
	{
		min = min_node(*a);
		if (min == NULL)
			return ;
		if (min->below_avg == TRUE)
			while (min != *a)
				rr(a, b, STACK_A);
		else
			while (min != *a)
				rrr(a, b, STACK_A);
		pp(a, b, STACK_B);
	}
	light_sort(a, b);
	while (*b)
		pp(a, b, STACK_A);
}

void	move_cheapest_to_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->below_avg && cheapest->target->below_avg)
		while (cheapest != *b && cheapest->target != *a)
			rr(a, b, STACK_AB);
	else if (!cheapest->below_avg && !cheapest->target->below_avg)
		while (cheapest != *b && cheapest->target != *a)
			rrr(a, b, STACK_AB);
	while (cheapest != *b)
	{
		if (cheapest->below_avg)
			rr(a, b, STACK_B);
		else
			rrr(a, b, STACK_B);
	}
	while (cheapest->target != *a)
	{
		if (cheapest->target->below_avg)
			rr(a, b, STACK_A);
		else
			rrr(a, b, STACK_A);
	}
}

void	heavy_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*cheapest;

	while (stacksize(*a) > 3)
		pp(a, b, STACK_B);
	light_sort(a, b);
	while (*b)
	{
		set_target(*a, *b);
		set_price(*a, *b);
		cheapest = set_cheapest(*b);
		move_cheapest_to_a(a, b, cheapest);
		pp(a, b, STACK_A);
	}
	min = min_node(*a);
	while (min != *a)
	{
		if (min->below_avg)
			rr(a, b, STACK_A);
		else
			rrr(a, b, STACK_A);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	if (is_sorted(*a))
		return ;
	stackpos(*a);
	size = stacksize(*a);
	if (size == 2)
		ss(a, b, STACK_A);
	else if (size == 3)
		light_sort(a, b);
	else if (size > 3 && size < 8)
		mid_sort(a, b);
	else
		heavy_sort(a, b);
}
