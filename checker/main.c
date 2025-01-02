/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:08:12 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/02 14:57:35 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	b = NULL;
	a = parser(ac, av, strs);
	if (strs)
		free_av(strs);
	if (a == NULL)
		return (1);
	stackfree(&a);
	return (0);
}
