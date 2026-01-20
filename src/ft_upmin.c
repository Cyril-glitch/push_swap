/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upmin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:26:08 by cycolonn          #+#    #+#             */
/*   Updated: 2026/01/20 14:26:18 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_upmin(t_clist **stack_a, t_clist **stack_b)
{
	t_clist	*min;
	int		size;

	size = (*stack_a)->prev->index + 1;
	min = ft_stack_min(*stack_a);
	if (min->index <= (size / 2))
	{
		while (*stack_a != min)
			ft_rotate("ra", stack_a, stack_b);
	}
	else
	{
		while (*stack_a != min)
			ft_reverse("rra", stack_a, stack_b);
	}
}
