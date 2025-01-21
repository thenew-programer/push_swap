/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:45:49 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/21 22:17:29 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_ops(t_ops *ops)
{
	ops[0] = (t_ops){"sa", ss};
	ops[1] = (t_ops){"sb", ss};
	ops[2] = (t_ops){"ss", ss};
	ops[3] = (t_ops){"ra", rr};
	ops[4] = (t_ops){"rb", rr};
	ops[5] = (t_ops){"rr", rr};
	ops[6] = (t_ops){"rra", rrr};
	ops[7] = (t_ops){"rrb", rrr};
	ops[8] = (t_ops){"rrr", rrr};
	ops[9] = (t_ops){"pa", pp};
	ops[10] = (t_ops){"pb", pp};
	ops[11] = (t_ops){NULL, NULL};
}

int	exec_op(char *op, t_stack **a, t_stack **b, t_ops *sort_ops)
{
	int	j;

	j = 0;
	while (sort_ops[j].op)
	{
		if (ft_strncmp(op, sort_ops[j].op, ft_strlen(op)) == 0)
		{
			if (ft_strrchr(sort_ops[j].op, 'a'))
				sort_ops[j].f(a, b, STACK_A);
			else if (ft_strrchr(sort_ops[j].op, 'b'))
				sort_ops[j].f(a, b, STACK_B);
			else
				sort_ops[j].f(a, b, STACK_AB);
		}
		else
			return (input_error(NULL, TRUE), FALSE);

		j++;
	}
	return (TRUE);
}

t_const	sort(char **ops, t_stack **a, t_stack **b)
{
	t_ops	sort_ops[12];
	int		i;

	init_ops(sort_ops);
	if (!ops && is_sorted(*a))
		return (ft_putendl_fd("OK", 1), TRUE);
	if (!ops)
		return (ft_putendl_fd("KO", 1), FALSE);
	i = 0;
	while (ops[i])
	{
		if (exec_op(ops[i], a, b, sort_ops) == FALSE)
			return (FALSE);
		i++;
	}
	if (!is_sorted(*a))
		return (ft_putendl_fd("KO", 1), FALSE);
	else
		return (ft_putendl_fd("OK", 1), TRUE);
}
