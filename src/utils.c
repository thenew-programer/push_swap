/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:42:56 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/12 10:15:10 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_stack	*rotate(t_stack *s)
{
	// int	*arr;
	int	first;
	int	i;

	if (is_empty(s) == TRUE)
		return (s);
	// arr = (int *)malloc(sizeof(int) * (s->top + 1));
	// if (!arr)
	// 	return (free_stack(s), NULL);
	// arr[0] = peek(s);
	first = peek(s);
	i = s->top;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = first;
	// free(s->arr);
	// s->arr = arr;
	return (s);
}

t_stack	*rrotate(t_stack *s)
{
	// int	*arr;
	int	last;
	int	i;

	if (is_empty(s) == TRUE)
		return (s);
	// arr = (int *)malloc(sizeof(int) * (s->top + 1));
	// if (!arr)
	// 	return (free_stack(s), NULL);
	i = 0;
	last = s->arr[0];
	while (i < s->top)
	{
		s->arr[i] = s->arr[i + 1];
		// arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->top] = last;
	// free(s->arr);
	// s->arr = arr;
	return (s);
}

t_const	is_sorted(t_stack *s)
{
	int	i;

	i = s->top;
	while (i > 0)
	{
		if (s->arr[i] > s->arr[i - 1])
			return (FALSE);
		i--;
	}
	return (TRUE);
}

int	max_pos(t_stack *s)
{
	int	max;
	int	i;

	max = s->top;
	i = max - 1;
	while (i >= 0)
	{
		if (s->arr[i] > s->arr[max])
			max = i;
		i--;
	}
	return (max);
}

int	min_pos(t_stack *s)
{
	int	min;
	int	i;

	min = s->top;
	i = min - 1;
	while (i >= 0)
	{
		if (s->arr[i] < s->arr[min])
			min = i;
		i--;
	}
	return (min);
}

int	count_op(t_stack *s, int idx, t_const *direction)
{
	int	rr_ops;

	if (idx < 0 || idx > s->top)
		return (-1);
	rr_ops = (s->top - idx);
	if (++idx <= rr_ops)
	{
		*direction = BACKWARD;
		return (idx);
	}
	else
	{
		*direction = FORWARD;
		return (rr_ops);
	}
}

int	find_median(t_stack *a)
{
	int	median;

	median = a->top / 2;
	return (median);
}

t_stack	*set_target(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	small_bigger;
	int	target;

	if (b->target)
		free(b->target);
	b->target = (int *)malloc(sizeof(int) * (b->top + 1));
	if (!b->target)
		return (NULL);
	i = b->top;
	small_bigger = INT_MAX;
	while (i >= 0)
	{
		j = a->top;
		while (j >= 0)
		{
			if (a->arr[j] > b->arr[i] && a->arr[j] > small_bigger)
			{
				small_bigger = a->arr[j];
				target = a->arr[j];
			}
			j--;
		}
		if (small_bigger == INT_MAX)
			b->target[i] = a->arr[min_pos(a)];
		else
			b->target[i] = target;
		i--;
	}
	return (b);
}

int	find_pos(int elm, t_stack *s)
{
	int	i;

	i = s->top;
	while (i >= 0)
	{
		if (s->arr[i] == elm)
			return (i);
		i--;
	}
	return (-1);
}

t_stack	*calc_price(t_stack *a, t_stack *b)
{
	int	i;

	i = b->top;
	if (b->price)
		free(b->price);
	b->price = (int *)malloc(sizeof(int) * (b->top + 1));
	if (!b->price)
		return (NULL);
	while (i >= 0)
	{
		b->price[i] = i;
		if (b->arr[i] < b->median)
			b->price[i] = b->top - i;
		if (b->target[i] > a->median)
			b->price[i] += find_pos(b->target[i], a);
		else
			b->price[i] += a->top - find_pos(b->target[i], a);
		i--;
	}
	return (b);
}

void	set_cheapest(t_stack *s)
{
	int	i;
	int	min;

	min = s->price[s->top];
	i = s->top - 1;
	while (i >= 0)
	{
		if (s->price[i] < min)
		{
			min = s->price[i];
			s->cheapest = s->arr[i];
			s->pos_cheapest = i;
		}
		i--;
	}
}

void	set_pref(t_stack *a, t_stack *b)
{
	a->median = find_median(a);
	b->median = find_median(b);
	set_target(a, b);
	calc_price(a, b);
	set_cheapest(b);
}
