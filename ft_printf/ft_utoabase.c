/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:35:13 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 18:47:03 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_numalloc(unsigned long nbr, const char *base)
{
	int	i;
	int	baselen;

	i = (nbr == 0);
	baselen = ft_strlen(base);
	while (nbr)
	{
		nbr /= baselen;
		i++;
	}
	return (i);
}

char	*ft_utoabase(unsigned long nbr, const char *base)
{
	int		baselen;
	int		newlen;
	char	*new;

	baselen = ft_strlen(base);
	newlen = ft_numalloc(nbr, base);
	new = malloc(sizeof(char) * (newlen + 1));
	if (!new)
		return (NULL);
	new[newlen] = 0;
	while (newlen)
	{
		new[--newlen] = base[nbr % baselen];
		nbr /= baselen;
	}
	return (new);
}
