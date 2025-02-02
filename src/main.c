/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:03:05 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/01 08:40:58 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = parser(ac - 1, (av + 1));
	if (a == NULL)
		return (1);
	b = NULL;
	push_swap(&a, &b);
	stackfree(&a);
	stackfree(&b);
	return (0);
}
