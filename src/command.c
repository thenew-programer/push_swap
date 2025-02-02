/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:44:42 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/31 19:49:51 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
	{
		ft_putstr_fd("sa\n", 1);
		swap_node(a);
	}
	else if (flag == STACK_B)
	{
		ft_putstr_fd("sb\n", 1);
		swap_node(b);
	}
	else if (flag == STACK_AB)
	{
		ft_putstr_fd("ss\n", 1);
		swap_node(a);
		swap_node(b);
	}
	stackpos(*a);
	stackpos(*b);
}

void	rr(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
	{
		ft_putstr_fd("ra\n", 1);
		rotate(a);
	}
	else if (flag == STACK_B)
	{
		ft_putstr_fd("rb\n", 1);
		rotate(b);
	}
	else if (flag == STACK_AB)
	{
		ft_putstr_fd("rr\n", 1);
		rotate(a);
		rotate(b);
	}
	stackpos(*a);
	stackpos(*b);
}

void	rrr(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
	{
		ft_putstr_fd("rra\n", 1);
		rrotate(a);
	}
	else if (flag == STACK_B)
	{
		ft_putstr_fd("rrb\n", 1);
		rrotate(b);
	}
	else if (flag == STACK_AB)
	{
		ft_putstr_fd("rrr\n", 1);
		rrotate(a);
		rrotate(b);
	}
	stackpos(*a);
	stackpos(*b);
}

#define malloc(x) NULL
void	pp(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
	{
		ft_putstr_fd("pa\n", 1);
		push(a, pop(b));
	}
	else if (flag == STACK_B)
	{
		ft_putstr_fd("pb\n", 1);
		push(b, pop(a));
	}
	stackpos(*a);
	stackpos(*b);
}
