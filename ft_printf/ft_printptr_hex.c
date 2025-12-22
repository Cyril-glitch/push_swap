/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:10:13 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 18:10:46 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

static void	ft_localdisable(t_flags *f)
{
	f->zero = 0;
	f->dot = 0;
	f->hash = 0;
	f->space = 0;
	f->plus = 0;
	f->precision = 0;
}

int	ft_printptr_hex(void *ptr, t_flags *f)
{
	unsigned long	uptr;
	char			*p;
	char			*mid;
	char			*prefix;

	if (!ptr)
		return (ft_padandprint("(nil)", f));
  ft_localdisable(f);
	uptr = (unsigned long)ptr;
	p = ft_utoabase(uptr, "0123456789abcdef");
	if (p)
		prefix = "0x";
	else
		prefix = "";
	mid = ft_midcontent(prefix, p);
	return (ft_padandprint(mid, f));
}
