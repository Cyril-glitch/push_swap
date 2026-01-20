/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findminmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:02:51 by cycolonn          #+#    #+#             */
/*   Updated: 2026/01/20 14:02:59 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_clist	*ft_stack_min(t_clist *stack)
{
	t_clist	*compared;
	t_clist	*min;

	if (!stack)
		return (NULL);
	min = stack;
	compared = stack->next;
	while (compared != stack)
	{
		if (min->content > compared->content)
			min = compared;
		compared = compared->next;
	}
	return (min);
}

t_clist	*ft_stack_max(t_clist *stack)
{
	t_clist	*compared;
	t_clist	*max;

	if (!stack)
		return (NULL);
	max = stack;
	compared = stack->next;
	while (compared != stack)
	{
		if (max->content < compared->content)
			max = compared;
		compared = compared->next;
	}
	return (max);
}
