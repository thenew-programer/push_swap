/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:53:15 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/02 14:53:16 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

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
	s->prev = NULL;
	s->target = NULL;
	return (s);
}

void	stackadd_front(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp;
	int		pos;

	pos = 0;
	if (*head == NULL)
	{
		new_node->pos = pos;
		*head = new_node;
		return ;
	}
	tmp = *head;
	new_node->next = tmp;
	(*head)->prev = new_node;
	*head = new_node;
	tmp = new_node;
	while (tmp)
	{
		tmp->pos = pos;
		tmp = tmp->next;
		pos++;
	}
}

int	stacksize(t_stack *head)
{
	int	size;

	size = 0;
	while (head != NULL)
	{
		head = head->next;
		size++;
	}
	return (size);
}

void	stackfree(t_stack **head)
{
	t_stack	*curr;
	t_stack	*next;

	if (!head)
		return ;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}

t_stack	*stacklast(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}
