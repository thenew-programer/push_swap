/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:08:12 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/21 22:17:40 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*read_ops(void)
{
	char	*s;
	char	*tmp;
	char	*tmp1;

	s = ft_strdup("");
	tmp = get_next_line(STDIN_FILENO);
	if (!tmp)
		return (free(s), NULL);
	while (tmp)
	{
		tmp1 = s;
		s = ft_strjoin(tmp1, tmp);
		free(tmp1);
		free(tmp);
		tmp = get_next_line(STDIN_FILENO);
	}
	return (s);
}

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
	strs = parse_ops(read_ops());
	// if (strs)
	// {
	// 	for (int i = 0; strs[i]; i++)
	// 		printf("%s", strs[i]);
	// }
	sort(strs, &a, &b);
	stackfree(&b);
	stackfree(&a);
	return (0);
}
