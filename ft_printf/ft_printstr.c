/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:05:05 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 18:07:04 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

static void	ft_local_disable(t_flags *f)
{
	f->zero = 0;
	f->hash = 0;
	f->space = 0;
	f->plus = 0;
}

int	ft_printstr(char *s, t_flags *f)
{
	char	*precision;

  ft_local_disable(f);
	precision = ft_precision_str(s, f);
	return (ft_padandprint(precision, f));
}
