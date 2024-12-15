/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:40:03 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/08 13:19:18 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*parse(int ac, char **av)
{
	int		i;
	int		tmp;
	t_stack	*s;

	s = init_stack();
	if (!s)
		return (NULL);
	s->arr = (int *)malloc(sizeof(int) * (ac - 1));
	i = ac - 1;
	while (i > 0)
	{
		tmp = ft_atoi(av[i]);
		if (tmp == 0 && av[i][0] != '-' && !ft_isdigit(av[i][0]))
			return (free_stack(s), NULL);
		push(s, tmp);
		i--;
	}
	return (s);
}
