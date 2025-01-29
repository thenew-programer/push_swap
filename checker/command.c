/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:56:44 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/02 14:56:47 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
		swap_node(a);
	else if (flag == STACK_B)
		swap_node(b);
	else if (flag == STACK_AB)
	{
		swap_node(a);
		swap_node(b);
	}
}

void	rr(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
		rotate(a);
	else if (flag == STACK_B)
		rotate(b);
	else if (flag == STACK_AB)
	{
		rotate(a);
		rotate(b);
	}
}

void	rrr(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
		rrotate(a);
	else if (flag == STACK_B)
		rrotate(b);
	else if (flag == STACK_AB)
	{
		rrotate(a);
		rrotate(b);
	}
}

void	pp(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
		push(a, pop(b));
	else if (flag == STACK_B)
		push(b, pop(a));
}
