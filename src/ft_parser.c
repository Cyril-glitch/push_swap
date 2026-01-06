#include  "../inc/push_swap.h"

static  void ft_convertnode(char *av, t_clist **new) 
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
    ft_clstadd_back(new, ft_clstnew(nbr));
    i++;
  }
  ft_checkdup(tab, new);
  ft_freedtab(tab);
}

t_clist *ft_parser(int ac, char **av)
{
  int i;
  t_clist *new;

  i = 1;
  new = NULL;
  while (i < ac)
  {
    ft_convertnode(av[i], &new);
    i++;
  }
  return  (new);
}
