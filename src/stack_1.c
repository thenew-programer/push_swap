/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:30:22 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/01 23:08:16 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int data)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->data = data;
	s->below_avg = FALSE;
	s->cheapest = FALSE;
	s->next = NULL;
	s->target = NULL;
	return (s);
}

void	stackadd_front(t_stack **head, t_stack *new_node)
{
	new_node->next = (*head);
	*head = new_node;
}

int	stacksize(t_stack *s)
{
	int	size;

	size = 0;
	while (s != NULL)
	{
		s = s->next;
		size++;
	}
	return (size);
}

void	stackfree(t_stack **s)
{
	t_stack	*curr;
	t_stack	*next;

	curr = *s;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*s = NULL;
}

t_stack	*stacklast(t_stack *s)
{
	if (s == NULL)
		return (NULL);
	while (s->next)
	{
		s = s->next;
	}
	return (s);
}
