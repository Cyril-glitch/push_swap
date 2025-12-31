#include  "../inc/push_swap.h"

static int ft_duplicates(char **tab)
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
        return (1);
      j++;
    }
    i++;
  }
  return (0);
}

static  int ft_nodigit(char **tab)
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
        return (1);
      j++;
    }
    i++;
  }
  return (0);
}

static void ft_checkargs(char **tab)
{
  if (ft_duplicates(tab))
    ft_error(NULL, NULL);
  else if (ft_nodigit(tab))
    ft_error(NULL, NULL); 
}

static  void ft_convert(char *av, t_dlist **new)
{
  int i;
  long  nbr;
  char  **tab;

  i = 0;
  tab = ft_split(av, ' ');
  ft_checkargs(tab);
  while (tab[i])
  {
    nbr = ft_atol(tab[i]);
    if (nbr < INT_MIN || nbr > INT_MAX)
      ft_error(NULL,NULL);
    ft_dlstadd_back(new, ft_dlstnew(nbr));
    if (!new)
      ft_error(new, NULL);
    i++;
  }
  ft_freeiter(tab, i);
}

t_dlist *ft_parser(int ac, char **av)
{
  int i;
  t_dlist *new;

  i = 1;
  new = NULL;
  while (i < ac)
  {
    ft_convert(av[i], &new);
    i++;
  }
  return  (new);
}
