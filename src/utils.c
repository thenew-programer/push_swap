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
	int	*arr;
	int	i;

	if (is_empty(s) == TRUE)
		return (s);
	arr = (int *)malloc(sizeof(int) * s->top);
	if (!arr)
		return (free_stack(s), NULL);
	arr[0] = peek(s);
	i = 1;
	while (i <= s->top)
	{
		arr[i] = s->arr[i - 1];
		i++;
	}
	free(s->arr);
	s->arr = arr;
	return (s);
}

t_stack	*rrotate(t_stack *s)
{
	int	*arr;
	int	i;

	if (is_empty(s) == TRUE)
		return (s);
	arr = (int *)malloc(sizeof(int) * s->top);
	if (!arr)
		return (free_stack(s), NULL);
	i = 0;
	while (i < s->top)
	{
		arr[i] = s->arr[i + 1];
		i++;
	}
	arr[i] = s->arr[0];
	free(s->arr);
	s->arr = arr;
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

int	count_op(t_stack *s, int idx)
{
	int	offset;
	int	ops;

	offset = s->top - idx;
	ops = 0;
	if (offset == s->top)
		ops = s->top + 1;
	else if (offset < s->top / 2)
		ops = s->top + offset;
	else if (offset >= s->top / 2)
		ops = offset;
	return (ops);
}
