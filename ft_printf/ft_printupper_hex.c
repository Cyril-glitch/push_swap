/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printupper_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:14:59 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 18:15:19 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_localdisable(t_flags *f)
{
	f->space = 0;
	f->plus = 0;
	f->precision = 0;
	f->width = 0;
}

int	ft_printupper_hex(unsigned int n, t_flags *f)
{
	char	*nbr;
	char	*prefix;
	char	*precise;
	char	*mid;

  ft_localdisable(f);
	nbr = ft_utoabase((unsigned long)n, "0123456789ABCDEF");
	prefix = ft_prefix(n, 'X', f);
	precise = ft_precision_nbr(nbr, f);
	mid = ft_midcontent(prefix, precise);
	return (ft_padandprint(mid, f));
}
