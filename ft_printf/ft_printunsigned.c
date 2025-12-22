/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:12:00 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 18:13:03 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

static void	ft_local_disable(t_flags *f)
{
	f->hash = 0;
	f->hash = 0;
	f->space = 0;
	f->plus = 0;
}

int	ft_printunsigned(unsigned int n, t_flags *f)
{
	char	*nbr;
	char	*precise;
	char	*prefix;

	ft_local_disable(f);
	nbr = ft_utoabase((unsigned long)n, "0123456789");
	precise = ft_precision_nbr(nbr, f);
	return (ft_padandprint(precise, f));
}
