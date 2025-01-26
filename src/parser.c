/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:54:43 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/31 22:19:12 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_av(char **av)
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

t_const	is_nbr_valid(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		if (sign == 1 && (result > (INT_MAX - (*str - '0')) / 10))
			return (FALSE);
		if (sign == -1 && (-result < (INT_MIN + (*str - '0')) / 10))
			return (FALSE);
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (TRUE);
}

char	**parse_av(int *ac, char *str)
{
	char	**strs;
	int		count;

	strs = ft_split(str, ' ');
	count = 0;
	while (strs[count])
		count++;
	*ac = count;
	return (strs);
}

t_stack	*parser(int ac, char **av)
{
	t_stack	*head;
	int		nbr;
	int		i;

	if (av == NULL)
		return (input_error(NULL, TRUE), NULL);
	head = NULL;
	i = ac - 1;
	while (i >= 0)
	{
		nbr = ft_atoi(av[i]);
		if (stackfind(head, nbr) != NULL || !is_nbr_valid(av[i]))
			return (input_error(&head, TRUE), NULL);
		if (push(&head, nbr) == 0)
			return (input_error(&head, FALSE), NULL);
		i--;
	}
	return (head);
}
