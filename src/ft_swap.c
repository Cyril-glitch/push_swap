/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:25:04 by cycolonn          #+#    #+#             */
/*   Updated: 2026/01/20 14:25:08 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_swapping(t_clist **head)
{
	t_clist	*second;
	t_clist	*last;
	t_clist	*third;

	second = (*head)->next;
	last = (*head)->prev;
	third = second->next;
	if (!*head || second == *head)
		return ;
	if (third == (*head))
	{
		(*head) = second;
		return ;
	}
	second->next = (*head);
	second->prev = last;
	(*head)->next = third;
	(*head)->prev = second;
	last->next = second;
	third->prev = (*head);
	(*head) = second;
}

void	ft_swap(const char *mode, t_clist **stack_a, t_clist **stack_b)
{
	if (ft_strcmp(mode, "sa") == 0)
	{
		ft_swapping(stack_a);
		write(1, "sa\n", 3);
	}
	else if (ft_strcmp(mode, "sb") == 0)
	{
		ft_swapping(stack_b);
		write(1, "sb\n", 3);
	}
	else if (ft_strcmp(mode, "ss") == 0)
	{
		ft_swapping(stack_a);
		ft_swapping(stack_b);
		write(1, "ss\n", 3);
	}
}
