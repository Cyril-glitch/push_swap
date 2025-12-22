/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:42:54 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/17 16:43:05 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main (int ac, char **av)
{
  if(ac < 2)
    return 0;

  int fd = 0; 
  char  buf = 0;

  fd = ft_rdw_open(av[1]);
  ft_putchar_fd('Z',fd);
  fd = ft_ropen(av[1]);
  ft_cat(fd,&buf);
  close(fd);
}
*/
