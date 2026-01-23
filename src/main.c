/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:27:05 by cycolonn          #+#    #+#             */
/*   Updated: 2026/01/21 15:51:33 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_clist	*stack_a;
	t_clist	*stack_b;

	if (ac < 2)
		ft_leavefree(NULL, NULL);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_parser(ac, av);
	if (!stack_a)
		ft_leavefree(&stack_a, NULL);
	if (ft_check_sorted(&stack_a))
		ft_leavefree(&stack_a, NULL);
	if (ft_stacksize(stack_a) < 6)
		ft_little_sort(&stack_a, &stack_b);
	else
		ft_big_sort(&stack_a, &stack_b);
	ft_clstclear(&stack_a);
	ft_clstclear(&stack_b);
}
