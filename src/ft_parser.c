/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:23:08 by cycolonn          #+#    #+#             */
/*   Updated: 2026/01/21 16:26:41 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_convertnode(char *av, t_clist **new)
{
	int		i;
	long	nbr;
	char	**tab;

	i = 0;
	tab = ft_split(av, ' ');
	if (!tab)
		ft_leavefree(new, NULL);
	if (!*tab)
		ft_error(tab, new, NULL);
	ft_checkdigit(tab, new);
	while (tab[i])
	{
		nbr = ft_atol(tab[i]);
		ft_check_overint(tab, new, nbr);
		ft_clstadd_back(new, ft_clstnew(nbr));
		i++;
	}
	ft_checkdup(tab, new);
	ft_freedtab(tab);
}

t_clist	*ft_parser(int ac, char **av)
{
	int		i;
	t_clist	*new;

	i = 1;
	new = NULL;
	while (i < ac)
	{
		if (!*av[i])
			ft_error(NULL, &new, NULL);
		ft_convertnode(av[i], &new);
		i++;
	}
	return (new);
}
