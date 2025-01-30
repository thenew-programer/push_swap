/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:45:49 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/28 11:51:27 by ybouryal         ###   ########.fr       */
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
		if (ft_strncmp(op, sort_ops[j].op, ft_strlen(op) - 1) == 0)
		{
			if (ft_strrchr(sort_ops[j].op, 'a'))
				return (sort_ops[j].f(a, b, STACK_A), TRUE);
			else if (ft_strrchr(sort_ops[j].op, 'b'))
				return (sort_ops[j].f(a, b, STACK_B), TRUE);
			else
				return (sort_ops[j].f(a, b, STACK_AB), TRUE);
		}
		j++;
	}
	return (FALSE);
}

char	*read_op(void)
{
	char	*op;

	op = get_next_line(STDIN_FILENO);
	if (!op)
		return (NULL);
	return (op);
}

int	sort(t_stack **a, t_stack **b, int a_size)
{
	t_const	ret;
	t_ops	sort_ops[12];
	char	*op;
	int		size;

	init_ops(sort_ops);
	op = read_op();
	while (op)
	{
		if (exec_op(op, a, b, sort_ops) == FALSE)
			return (free(op), input_error(a, TRUE), stackfree(b), FALSE);
		free(op);
		op = read_op();
	}
	ret = is_sorted(*a);
	size = stacksize(*a);
	stackfree(a);
	stackfree(b);
	if (!ret || size != a_size)
		return (ft_putendl_fd("KO", 1), FALSE);
	else
		return (ft_putendl_fd("OK", 1), FALSE);
	return (TRUE);
}
