/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:31:16 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 17:59:45 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	precision;
	int	width;
}	t_flags;

// fonction principal
int		ft_printf(const char *s, ...);

// fonction de conversion
int		ft_printchar(int c, t_flags *f);
int		ft_printstr(char *s, t_flags *f);
int		ft_printnbr(int n, t_flags *f);
int		ft_printptr_hex(void *ptr, t_flags *f);
int		ft_printptr_nbr(void *ptr, t_flags *f);
int		ft_printunsigned(unsigned int n, t_flags *f);
int		ft_printlower_hex(unsigned int n, t_flags *f);
int		ft_printupper_hex(unsigned int n, t_flags *f);

// ft_flags_utils.c
t_flags	*ft_flaginit(void);
int		ft_enableflags(const char *str, t_flags *f);
void	ft_normalize(t_flags *f);
void	ft_flagstate(t_flags *f);
void	ft_flagzero(t_flags *f);
int   ft_invalideflags(char end, t_flags *f);

// ft_format_utils.c
char	*ft_utoabase(unsigned long nbr, const char *base);
char	*ft_prefix(long n, char conv, t_flags *f);
char	*ft_precision_str(char *str, t_flags *f);
char	*ft_precision_nbr(char *nbr, t_flags *f);
char	*ft_midcontent(char *prefix, char *precise);
int		ft_padandprint(char *mid, t_flags *f);

#endif
