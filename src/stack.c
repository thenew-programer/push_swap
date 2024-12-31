/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:36:13 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/12 10:15:22 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (s)
	{
		s->top = -1;
		s->arr = NULL;
	}
	return (s);
}

void	push(t_stack *s, int n)
{
	s->arr[++s->top] = n;
}

int	pop(t_stack *s)
{
	return (s->arr[s->top--]);
}

int	peek(t_stack *s)
{
	return (s->arr[s->top]);
}

t_const	is_empty(t_stack *s)
{
	if (s->top == -1)
		return (TRUE);
	return (FALSE);
}

void	print_stack(t_stack *s)
{
	int	i;

	if (is_empty(s))
		return ;
	i = s->top;
	while (i >= 0)
	{
		ft_putnbr_fd(s->arr[i], 1);
		ft_putchar_fd(' ', 1);
		i--;
	}
	ft_putchar_fd('\n', 1);
}

void	free_stack(t_stack *s)
{
	if (s && s->arr)
		free(s->arr);
	if (s)
		free(s);
}
