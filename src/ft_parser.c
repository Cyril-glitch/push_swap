#include  "../inc/push_swap.h"

static  void ft_convertnode(char *av, t_dlist **new) 
{
  int i;
  long  nbr;
  char  **tab;

  i = 0;
  tab = ft_split(av, ' ');
  if (!tab)
    ft_error(tab,new,NULL);
  ft_checkdigit(tab, new);
  while (tab[i])
  {
    nbr = ft_atol(tab[i]);
    ft_check_overint(tab, new, nbr);
    ft_dlstadd_back(new, ft_dlstnew(nbr));
    i++;
  }
  ft_checkdup(tab, new);
  ft_freedtab(tab);
}

t_dlist *ft_parser(int ac, char **av)
{
  int i;
  t_dlist *new;

  i = 1;
  new = NULL;
  while (i < ac)
  {
    ft_convertnode(av[i], &new);
    i++;
  }
  return  (new);
}
