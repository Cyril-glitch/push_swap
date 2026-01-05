#include  "../inc/push_swap.h"

void  ft_push(const char mode, t_dlist **stack_a, t_dlist **stack_b)
{
  if (ft_strcmp(mode, "pa") == 0)
    ft_pusher(stack_a);
  else if (ft_strcmp(mode, "pb") == 0)
    ft_pusher(stack_b);
}
