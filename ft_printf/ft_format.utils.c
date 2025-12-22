/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:17:12 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 18:21:03 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_precision_str(char *str, t_flags *f)
{
	int		len;
	char	*precise;

	if (f->dot && !str || f->dot && f->precision == 0)
		return (ft_strdup(""));
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if ((!f->dot && !f->precision) || f->precision > len)
		return (str);
	else
		precise = malloc(sizeof(char) * (f->precision + 1));
	if (!precise)
		return (NULL);
	ft_bzero(ft_mempcpy(precise, str, f->precision), 1);
	return (precise);
}

static char	*ft_precision_zero(char *precise, char *nbr, t_flags *f)
{
	int	i;
	int	j;
	int	nbrlen;

	i = 0;
	j = 0;
	nbrlen = ft_strlen(nbr);
	while (i < (f->precision - nbrlen))
		precise[i++] = '0';
	while (j < nbrlen)
		precise[i++] = nbr[j++];
	precise[i] = 0;
	return (precise);
}

char	*ft_precision_nbr(char *nbr, t_flags *f)
{
	int		len;
	char	*precise;

	if (f->dot && nbr == 0 || f->dot && f->precision == 0)
		return (ft_strdup(""));
	len = ft_strlen(nbr);
	if ((!f->dot && !f->precision) || f->precision < len)
		return (nbr);
	precise = malloc(sizeof(char) * (f->precision + 1));
	if (!precise)
		return (NULL);
	return (ft_precision_zero(precise, nbr, f));
}

char	*ft_prefix(long n, char conv, t_flags *f)
{
	if (n < 0)
		return (ft_strdup("-"));
	else if (f->hash && conv == 'x' && n > 0)
		return (ft_strdup("0x"));
	else if (f->hash && conv == 'X' && n > 0)
		return (ft_strdup("0X"));
	else if (f->space)
		return (ft_strdup(" "));
	else if (f->plus)
		return (ft_strdup("+"));
	return (ft_strdup(""));
}

char	*ft_midcontent(char *prefix, char *precise)
{
	return (ft_strjoin(prefix, precise));
}
