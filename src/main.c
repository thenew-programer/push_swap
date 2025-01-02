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
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**strs;

	strs = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
		strs = parse_av(&ac, av[ac - 1]);
	else if (ac > 2)
	{
		av = &(av[1]);
		ac--;
	}
	b = NULL;
	if (strs)
		av = strs;
	a = parser(ac, av);
	// printf("strs[0] = %s\n", strs[0]);
	// printf("strs[1] = %s\n", strs[1]);
	if (strs)
		free_av(strs);
	if (a == NULL)
		return (1);
	push_swap(&a, &b);
	stackfree(&a);
	return (0);
}
