#include  "../inc/push_swap.h"

void ft_checkdup(char **tab, t_clist **new)
{
  size_t  size;
  size_t  i;
  size_t  j;
  t_clist *current;
  t_clist *compared;

  i = 0;
  size = ft_stacksize(*new);
  current = *new; 
  while (i < size)
  {
    j = i + 1;
    compared = current->next;
    while (j < size)
    {

      if (current->content == compared->content)
        ft_error(tab,new,NULL);
      compared = compared->next;
      j++;
    }
    current = current->next;
    i++;
  }
}

void ft_checkdigit(char **tab, t_clist **new)
{
    int i;
    int j;

    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] == '-' ||  tab[i][j] == '+')
                j++;
            if (!ft_isdigit(tab[i][j]))
                ft_error(tab, new, NULL);
            j++;
        }
        i++;
    }
}

void  ft_check_overint(char **tab, t_clist **new, long nbr)
{
  if (nbr < INT_MIN || nbr > INT_MAX)
      ft_error(tab, new, NULL);
}

int    ft_check_sorted(t_clist **stack_a)
{
    t_clist *current;
    t_clist *compared;

    current = *stack_a;
    while (current->next != *stack_a)
    {
        compared = current->next;
        if (current->content > compared->content)
            return (0);
        current = compared;
    }
    return (1);
}
