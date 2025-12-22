/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:00:48 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 18:04:35 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

static void	ft_local_disable(t_flags *f)
{
	f->zero = 0;
	f->dot = 0;
	f->hash = 0;
	f->space = 0;
	f->plus = 0;
	f->precision = 0;
}

int	ft_printchar(int c, t_flags *f)
{
	char	mid[2];

	mid[0] = (char)c;
	mid[1] = 0;
	ft_local_disable(f);
	return (ft_padandprint(mid, f));
}
