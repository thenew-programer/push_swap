/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:05:38 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/01 23:06:19 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stackfind(t_stack *s, int data)
{
	if (!s)
		return (NULL);
	while (s)
	{
		if (s->data == data)
			return (s);
		s = s->next;
	}
	return (NULL);
}

t_stack	*stackget(t_stack *s, int idx)
{
	int	count;

	count = 0;
	while (s)
	{
		if (count == idx)
			return (s);
		count++;
		s = s->next;
	}
	return (NULL);
}

void	stackpos(t_stack *s)
{
	int		i;
	int		median;

	median = stacksize(s) / 2;
	i = 0;
	while (s)
	{
		s->below_avg = (i <= median);
		s->pos = i++;
		s = s->next;
	}
}

int	pop(t_stack **s)
{
	int		data;
	t_stack	*del;

	data = (*s)->data;
	del = *s;
	(*s) = (*s)->next;
	free(del);
	return (data);
}

int	push(t_stack **s, int data)
{
	t_stack	*new;

	new = stacknew(data);
	if (!new)
		return (FALSE);
	stackadd_front(s, new);
	return (TRUE);
}
