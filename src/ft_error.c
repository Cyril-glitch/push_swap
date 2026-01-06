#include  "../inc/push_swap.h"


void  ft_error(char **tab, t_clist **stack_a, t_clist **stack_b)
{
  if (tab)
    ft_freedtab(tab);
  if (stack_a)
    ft_clstclear(stack_a);
  if (stack_b)
    ft_clstclear(stack_b);

  ft_putstr_fd("Error\n", 2);
  exit(EXIT_FAILURE);
}
