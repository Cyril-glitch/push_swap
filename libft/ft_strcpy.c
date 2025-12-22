/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:48:01 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/18 12:48:57 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*p;

	p = NULL;
	p = ft_mempcpy(dst, src, ft_strlen(src));
	*p = '\0';
	return (dst);
}
