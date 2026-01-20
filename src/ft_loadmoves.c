/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:22:40 by cycolonn          #+#    #+#             */
/*   Updated: 2026/01/20 14:23:00 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_moves	*ft_movesinit(void)
{
	t_moves	*new;

	new = malloc(sizeof(t_moves));
	if (!new)
		exit(EXIT_FAILURE);
	new->ra = 0;
	new->rb = 0;
	new->rra = 0;
	new->rrb = 0;
	new->rr = 0;
	new->rrr = 0;
	return (new);
}

static void	ft_load_moves_0(t_clist *cheapest, t_moves *mv)
{
	mv->ra = cheapest->index;
	mv->rb = cheapest->target->index;
	if (mv->ra > mv->rb)
		mv->rr = mv->rb;
	else if (mv->ra < mv->rb)
		mv->rr = mv->ra;
	else if (mv->ra == mv->rb)
		mv->rr = mv->ra;
	mv->ra -= mv->rr;
	mv->rb -= mv->rr;
	if (mv->ra < 0)
		mv->ra = 0;
	if (mv->rb < 0)
		mv->rb = 0;
}

static void	ft_load_moves_1(t_clist *cheapest, t_moves *mv, int size,
		int size_b)
{
	if (cheapest->index > 0)
		mv->rra = size - cheapest->index;
	if (cheapest->target->index > 0)
		mv->rrb = size_b - cheapest->target->index;
	if (mv->rra > mv->rrb)
		mv->rrr = mv->rrb;
	else if (mv->rra < mv->rrb)
		mv->rrr = mv->rra;
	else if (mv->rra == mv->rrb)
		mv->rrr = mv->rra;
	mv->rra -= mv->rrr;
	mv->rrb -= mv->rrr;
	if (mv->rra < 0)
		mv->rra = 0;
	if (mv->rrb < 0)
		mv->rrb = 0;
}

static void	ft_load_moves_2and3(t_clist *cheapest, t_moves *mv, int size,
		int size_b)
{
	if (cheapest->strat == 2)
	{
		mv->ra = cheapest->index;
		if (cheapest->target->index > 0)
			mv->rrb = size_b - cheapest->target->index;
	}
	else if (cheapest->strat == 3)
	{
		if (cheapest->index > 0)
			mv->rra = size - cheapest->index;
		mv->rb = cheapest->target->index;
	}
}

t_moves	*ft_loadmoves(t_clist *cheapest, int size, int size_b)
{
	t_moves	*mv;

	mv = ft_movesinit();
	if (!mv)
		return (NULL);
	if (cheapest->strat == 0)
		ft_load_moves_0(cheapest, mv);
	else if (cheapest->strat == 1)
		ft_load_moves_1(cheapest, mv, size, size_b);
	else
		ft_load_moves_2and3(cheapest, mv, size, size_b);
	return (mv);
}
