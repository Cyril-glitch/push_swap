#include  "../inc/push_swap.h"

void ft_checkdup(char **tab, t_dlist **new)
{
  int i;
  int j;

  i = 0;
  while (tab[i])
  {
    j = i + 1;
    while (tab[j])
    {
      if (ft_strcmp(tab[i], tab[j]) == 0) 
        ft_error(tab, new, NULL);
      j++;
    }
    i++;
  }
}

void ft_checkdigit(char **tab, t_dlist **new)
{
  int i;
  int j;
  
  i = 0;
  while (tab[i])
  {
    j = 0;
    while (tab[i][j])
    {
      if (!ft_isdigit(tab[i][j]))
        ft_error(tab, new, NULL);
      j++;
    }
    i++;
  }
}

void  ft_check_overint(char **tab, t_dlist **new, long nbr)
{
  if (nbr < INT_MIN || nbr > INT_MAX)
      ft_error(tab, new, NULL);
}
