/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:05:09 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/18 14:08:36 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_countword(const char *s, char set)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (!ft_ischarset(s[i], set) && (ft_ischarset(s[i + 1], set)
				|| !s[i + 1]))
			n++;
		i++;
	}
	return (n);
}
