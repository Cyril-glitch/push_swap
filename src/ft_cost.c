/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:02:18 by cycolonn          #+#    #+#             */
/*   Updated: 2026/01/20 14:02:32 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_onecost(t_clist *node, int size, int size_b)
{
	int	i;
	int	j;
	int	tab[4];
	int	mincost;

	tab[0] = ft_strat_0(node);
	tab[1] = ft_strat_1(node, size, size_b);
	tab[2] = ft_strat_2(node, size_b);
	tab[3] = ft_strat_3(node, size);
	i = 0;
	j = 0;
	mincost = tab[0];
	while (i < 3)
	{
		if (mincost > tab[i + 1])
		{
			mincost = tab[i + 1];
			j = i + 1;
		}
		i++;
	}
	node->cost = mincost;
	node->strat = j;
}

void	ft_cost(t_clist **stack_a, int size, int size_b)
{
	t_clist	*tmp;
	t_clist	*lap;

	tmp = *stack_a;
	lap = NULL;
	while (lap != tmp)
	{
		ft_onecost(*stack_a, size, size_b);
		*stack_a = (*stack_a)->next;
		lap = *stack_a;
	}
}
