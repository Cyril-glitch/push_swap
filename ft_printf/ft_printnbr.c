/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:07:36 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 18:09:22 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_local_disable(t_flags *f)
{
	f->hash = 0;
}

static unsigned long	ft_abs(int n)
{
	unsigned long	abs;

	abs = 0;
	if (n < 0)
		n *= -1;
	abs = n;
	return (abs);
}

int	ft_printnbr(int n, t_flags *f)
{
	unsigned long	abs;
	char			*nbr;
	char			*precise;
	char			*mid;
	char			*prefix;

	ft_local_disable(f);
	abs = ft_abs(n);
	nbr = ft_utoabase(abs, "0123456789");
	prefix = ft_prefix(n, 'd', f);
	precise = ft_precision_nbr(nbr, f);
	mid = ft_midcontent(prefix, precise);
	return (ft_padandprint(mid, f));
}
