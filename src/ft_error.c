#include  "../inc/push_swap.h"


void  ft_error(t_dlist **stack_a, t_dlist **stack_b)
{
  if (stack_a)
    ft_dlstclear(stack_a);
  if (stack_b)
    ft_dlstclear(stack_b);

  ft_putstr_fd("Error\n", 2);
  exit(EXIT_FAILURE);
}
