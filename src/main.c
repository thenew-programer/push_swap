/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:35:50 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/08 13:34:17 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac <= 2)
		return (1);
	a = parse(ac, av);
	if (!a)
		return (ft_putstr_fd("Error\n", 2), 1);
	b = init_stack();
	b->arr = (int *)malloc(sizeof(int) * a->top);
	if (!b->arr)
		return (free_stack(a), free_stack(b), 1);
	printf("before:\n\t");
	print_stack(a);
	sort(a, b);
	printf("after:\n\t");
	print_stack(a);
	return (free_stack(a), free_stack(b), 0);
}
