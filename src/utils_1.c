/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:13:33 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/01 23:07:33 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_node(t_stack **s)
{
	t_stack	*second;

	second = (*s)->next;
	second->prev = NULL;
	(*s)->next = second->next;
	(*s)->prev = second;
	second->next = *s;
	*s = second;
}

void	rotate(t_stack **s)
{
	t_stack	*top;
	t_stack	*last;

	top = *s;
	last = stacklast(*s);
	if (last == NULL)
		return ;
	*s = top->next;
	(*s)->prev = NULL;
	last->next = top;
	top->prev = last;
	top->next = NULL;
}

void	rrotate(t_stack **s)
{
	t_stack	*last;

	last = stacklast(*s);
	if (last == NULL)
		return ;
	last->prev->next = NULL;
	last->next = *s;
	last->prev = NULL;
	(*s)->prev = last;
	*s = last;
}

t_const	is_sorted(t_stack *s)
{
	t_stack	*tmp;

	if (s == NULL)
		return (FALSE);
	while (s)
	{
		tmp = s->next;
		while (tmp)
		{
			if (s->data > tmp->data)
				return (FALSE);
			tmp = tmp->next;
		}
		s = s->next;
	}
	return (TRUE);
}

t_const	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (TRUE);
	return (FALSE);
}
