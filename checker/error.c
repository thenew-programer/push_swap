/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:23:42 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/21 21:23:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	input_error(t_stack **s, t_const msg)
{
	if (msg == TRUE)
		ft_putstr_fd("Error\n", 2);
	if (s != NULL)
		if (*s != NULL)
			stackfree(s);
}
