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

#include "checker.h"

int	swap_node(t_stack **s)
{
	t_stack	*second;

	if (!s)
		return (FALSE);
	second = (*s)->next;
	(*s)->next = second->next;
	second->next = *s;
	*s = second;
	return (TRUE);
}

int	rotate(t_stack **s)
{
	t_stack	*top;
	t_stack	*last;

	top = *s;
	last = stacklast(*s);
	if (last == NULL)
		return (FALSE);
	*s = top->next;
	last->next = top;
	top->next = NULL;
	return (TRUE);
}

int	rrotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*before_last;

	last = stacklast(*s);
	if (last == NULL)
		return (FALSE);
	before_last = stackget(*s, stacksize(*s) - 2);
	before_last->next = NULL;
	last->next = *s;
	*s = last;
	return (TRUE);
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
