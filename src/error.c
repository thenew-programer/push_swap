/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 22:10:35 by ybouryal          #+#    #+#             */
/*   Updated: 2024/12/31 22:16:35 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	input_error(t_stack **s, t_const msg)
{
	if (msg == TRUE)
		ft_putstr_fd("Error\n", 2);
	if (s)
		stackfree(s);
}
