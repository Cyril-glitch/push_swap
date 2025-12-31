#include  "../inc/libft.h"

long  ft_atol(const char *nbr)
{
  int  i;
  int  signe;
  long  res;

  i = 0;
  signe = 1;
  res = 0;
  while (ft_isspace(nbr[i]))
    i++;
  if (nbr[i] == '-' || nbr[i] == '+')
  {
    if (nbr[i] == '-')
      signe = -1;
    i++;
  }
  while (ft_isdigit(nbr[i]))
  {
    res *= 10;
    res += nbr[i] - '0';
    i++;
  }
  return (res * signe);
}
