/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leavefree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:29:09 by cycolonn          #+#    #+#             */
/*   Updated: 2026/01/20 14:29:52 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_leavefree(t_clist **stack_a, t_clist **stack_b)
{
	if (stack_a)
		ft_clstclear(stack_a);
	if (stack_b)
		ft_clstclear(stack_b);
	exit(EXIT_FAILURE);
}
