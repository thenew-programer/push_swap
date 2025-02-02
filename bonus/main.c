/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:08:12 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/02 11:03:50 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		ret;

	if (ac == 1)
		return (0);
	b = NULL;
	a = parser(&ac, (av + 1));
	if (!a)
		return (1);
	ret = sort(&a, &b, ac);
	stackfree(&b);
	stackfree(&a);
	if (ret == FALSE)
		return (1);
	return (0);
}
