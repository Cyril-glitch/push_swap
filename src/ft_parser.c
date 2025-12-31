#include  "push_swap.h"
#include  "libft/libft.h"

static void ft_convert(char *av, t_dlist **new)
{
  int i;
  long  nbr;
  char  **tab;

  i = 0;
  tab = ft_split(av, ' ');
  while (tab[i])
  {
    nbr = ft_atol(tab[i]);
    ft_dlstadd_front(new, ft_dlstnew(&nbr));
    if (!new)
      ft_error(new, NULL);
    i++;
  }
}

t_dlist *ft_parser(int ac, char **av)
{

  int i;
  t_dlist *new;

  i = 0;
  while (i < ac)
  {
    ft_convert(av[i], &new);
    i++;
  }
  return  (new);
}
