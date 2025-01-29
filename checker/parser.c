/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:38:13 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/28 11:38:47 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		if (*str++ == '-')
			sign = -1;
	if (!*(str))
		return (FALSE);
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
	if (!strs[0])
	{
		free_av(strs);
		input_error(NULL, TRUE);
		exit(1);
	}
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

char	**parse_ops(char *s)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = ft_split(s, '\n');
	free(s);
	if (!strs)
		return (NULL);
	return (strs);
}
