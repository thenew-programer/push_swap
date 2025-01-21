/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:52:00 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/21 21:23:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	free_av(char **av)
{
	int	i;

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
	while (strs[count] != NULL)
		count++;
	*ac = count;
	return (strs);
}

t_stack	*parser(int ac, char **av, char **strs)
{
	t_stack	*head;
	int		nbr;
	int		i;

	if (strs)
		av = strs;
	if (ac > 2)
	{
		ac--;
		av++;
	}
	head = NULL;
	i = ac - 1;
	while (i >= 0)
	{
		nbr = ft_atoi(av[i]);
		if ((nbr == 0 && av[i][0] != '+' && av[i][0] != '-' && !ft_isdigit(av[i][0]))
			|| stackfind(head, nbr) != NULL || !is_nbr_valid(av[i]))
			return (input_error(&head, TRUE), NULL);
		if (push(&head, nbr) == 0)
			return (input_error(&head, FALSE), NULL);
		i--;
	}
	if (strs)
		free_av(strs);
	return (head);
}

char	**parse_ops(char *s)
{
	char	**strs;
	char	*ops;
	// int		i;

	if (!s)
		return (NULL);
	ops = "sa ra rra pa sb rb rrb pb rrr ss rr";
	strs = ft_split(s, '\n');
	free(s);
	if (!strs)
		return (NULL);
	// i = 0;
	// while (strs[i])
	// {
	// 	if (ft_strnstr(ops, strs[i], ft_strlen(strs[i])) == NULL)
	// 		return (free_av(strs), NULL);
	// 	i++;
	// }
	return (strs);
}
