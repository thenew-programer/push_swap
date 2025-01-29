/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:08:12 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/28 11:51:38 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (strs)
		free_av(strs);
	if (!a)
		return (1);
	sort(&a, &b, ac);
	return (0);
}
