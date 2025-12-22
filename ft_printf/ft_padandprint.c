/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padandprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:31:52 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 18:33:56 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_leftpad(char *mid, int pad)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	count += write(1, mid, ft_strlen(mid));
	while (i < pad)
	{
		count += write(1, " ", 1);
		i++;
	}
	return (count);
}

static int	ft_rightpad(char *mid, int pad, t_flags *f)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < pad)
	{
		if (f->zero)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
		i++;
	}
	count += write(1, mid, ft_strlen(mid));
	return (count);
}

int	ft_padandprint(char *mid, t_flags *f)
{
	int	count;
	int	pad;

	pad = f->width - ft_strlen(mid);
	count = 0;
	if (f->minus)
		count += ft_leftpad(mid, pad);
	else
		count += ft_rightpad(mid, pad, f);
	return (count);
}
