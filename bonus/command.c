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

int	ss(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
		return (swap_node(a));
	else if (flag == STACK_B)
		return (swap_node(b));
	else if (flag == STACK_AB)
	{
		if (swap_node(a) == FALSE)
			return (FALSE);
		if (swap_node(b) == FALSE)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

int	rr(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
		return (rotate(a));
	else if (flag == STACK_B)
		return (rotate(b));
	else if (flag == STACK_AB)
	{
		if (rotate(a) == FALSE)
			return (FALSE);
		if (rotate(b) == FALSE)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

int	rrr(t_stack **a, t_stack **b, t_const flag)
{
	if (flag == STACK_A)
		return (rrotate(a));
	else if (flag == STACK_B)
		return (rrotate(b));
	else if (flag == STACK_AB)
	{
		if (rrotate(a) == FALSE)
			return (FALSE);
		if (rrotate(b) == FALSE)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

int	pp(t_stack **a, t_stack **b, t_const flag)
{
	int	nbr;

	if (flag == STACK_A)
	{
		nbr = pop(b);
		if (nbr == FALSE && !*b)
			return (FALSE);
		return (push(a, nbr));
	}
	else if (flag == STACK_B)
	{
		nbr = pop(a);
		if (nbr == FALSE && !*a)
			return (FALSE);
		return (push(b, nbr));
	}
	return (FALSE);
}
