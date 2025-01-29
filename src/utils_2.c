/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:07:44 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/01 23:08:10 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_node(t_stack *s)
{
	int		min;
	t_stack	*min_node;

	if (s == NULL)
		return (NULL);
	min = INT_MAX;
	min_node = NULL;
	while (s)
	{
		if (s->data < min)
		{
			min = s->data;
			min_node = s;
		}
		s = s->next;
	}
	return (min_node);
}

void	set_target(t_stack *a, t_stack *b)
{
	int		biggest_smallest;
	t_stack	*curr;
	t_stack	*target;

	while (b)
	{
		biggest_smallest = INT_MAX;
		target = min_node(a);
		curr = a;
		while (curr)
		{
			if (curr->data < biggest_smallest && curr->data > b->data)
			{
				biggest_smallest = curr->data;
				target = curr;
			}
			curr = curr->next;
		}
		b->target = target;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stacksize(a);
	size_b = stacksize(b);
	while (b)
	{
		b->price = b->pos;
		if (b->below_avg == FALSE)
			b->price = size_b - b->pos;
		if (b->target->below_avg)
			b->price += b->target->pos;
		else
			b->price += size_a - b->target->pos;
		b = b->next;
	}
}

t_stack	*set_cheapest(t_stack *b)
{
	int		min;
	t_stack	*cheapest;

	min = INT_MAX;
	while (b)
	{
		if (b->price < min)
		{
			min = b->price;
			cheapest = b;
		}
		b = b->next;
	}
	cheapest->cheapest = TRUE;
	return (cheapest);
}
