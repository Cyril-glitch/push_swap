/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:26:03 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/27 16:56:33 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static	int	ft_printconverter(char conv, t_flags *f, va_list args)
{
	int	count;

	count = 0;
	if (conv == 'c')
		count = ft_printchar(va_arg(args, int), f);
  else if (conv == 's')
		count = ft_printstr(va_arg(args, char *), f);
  else if (conv == 'p')
		count = ft_printptr_hex(va_arg(args, void *), f);
  else if (conv == 'd' || conv == 'i')
		count = ft_printnbr(va_arg(args, int), f);
  else if (conv == 'u')
		count = ft_printunsigned(va_arg(args, unsigned int), f);
  else if (conv == 'x')
		count = ft_printlower_hex(va_arg(args, unsigned int), f);
  else if (conv == 'X')
		count = ft_printupper_hex(va_arg(args, unsigned int), f);
  else if (conv == '%')
		count = write(1, "%", 2);
  else
    count = write(1, "%", 1);
	ft_flagzero(f);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	t_flags	*f;
	va_list	args;
	int		count;
	int		i;

  if (!str)
    return (0);
	f = ft_flaginit();
	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i += ft_enableflags(&str[i], f);
			count += ft_printconverter(str[i], f, args);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	free(f);
	return (count);
}


int main()
{
   int resft = 0;
   int res = 0;

//test %c
int  c = 'a';
resft = ft_printf("test %%c = |%20c|\n",c);
res = printf("test %%c = |%20c|\n",c);
printf("resft = %d\n",resft);
printf("res = %d\n",res);
printf("\n\n");

//test %s
char *s = NULL;
resft = ft_printf("test %%s = |%-10s|\n",s);
res = printf("test %%s = |%-10s|\n",s);
printf("resft = %d\n",resft);
printf("res = %d\n",res);
printf("\n\n");

int d = -42;
resft = ft_printf("test %%d = |%+.5d|\n",d);
res = printf("test %%d = |%+.5d|\n",d);
printf("resft = %d\n",resft);
printf("res = %d\n",res);
printf("\n\n");

char *p =NULL;
resft = ft_printf("test %%p = |%-30p|\n",p);
res = printf("test %%p = |%-30p|\n",p);
printf("resft = %d\n",resft);
printf("res = %d\n",res);
printf("\n\n");

unsigned int u;
u = 4294967295;
resft = ft_printf("test %%u = |%-40.30u|\n",u);
res = printf("test %%u = |%-40.30u|\n",u);
printf("resft = %d\n",resft);
printf("res = %d\n",res);
printf("\n\n");

unsigned int x;
x = 429496729;
resft = ft_printf("test %%x = |%-#40. 30x|\n",x);
res = printf("test %%x = |%-#40. 30x|\n",x);
printf("resft = %d\n",resft);
printf("res = %d\n",res);
printf("\n\n");

unsigned int X;
X = 429496729;
resft = ft_printf("test %%X = |%&--5---+.###5 |\n",X);
res = printf("test %%X = |%&---5--+.###5 |\n",X);
printf("resft = %d\n",resft);
printf("res = %d\n",res);
printf("\n\n");
}
