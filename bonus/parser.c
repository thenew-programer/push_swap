/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:38:13 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/02 10:59:41 by ybouryal         ###   ########.fr       */
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

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return (-1);
	while (strs[i])
		i++;
	return (i);
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

t_const	parse_nbrs(t_stack **head, char *s)
{

	char	**strs;
	int		i;
	int		nbr;

	strs = ft_split(s, ' ');
	i = ft_strslen(strs) - 1;
	if (i < 0)
		return (free_av(strs), input_error(head, TRUE), FALSE);
	while (i >= 0)
	{
		nbr = ft_atoi(strs[i]);
		if (stackfind(*head, nbr) || !is_nbr_valid(strs[i]))
			return (free_av(strs), input_error(head, TRUE), FALSE);
		if (push(head, nbr) == FALSE)
			return (free_av(strs), input_error(head, FALSE), FALSE);
		i--;
	}
	i = ft_strslen(strs);
	free_av(strs);
	return (i);
}

t_stack	*parser(int *ac, char **av)
{
	t_stack	*head;
	int		i;
	int		ret;

	if (av == NULL)
		return (input_error(NULL, TRUE), NULL);
	head = NULL;
	i = *ac - 1;
	*ac = 0;
	while (--i >= 0)
	{
		ret = parse_nbrs(&head, av[i]);
		if (ret == FALSE)
			return (NULL);
		*ac += ret;
	}
	return (head);
}
