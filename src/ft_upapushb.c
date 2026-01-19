#include  "../inc/push_swap.h"

void ft_upapushb(t_clist **stack_a, t_clist **stack_b)
{
  t_clist *target_a;
  int size;

  target_a = (*stack_b)->target;
  size = (*stack_a)->prev->index + 1;
  if (target_a->index <= (size / 2))
  {
    while(*stack_a != target_a)
      ft_rotate("ra", stack_a, stack_b);
  }
  else
  {
    while(*stack_a != target_a)
      ft_reverse("rra", stack_a, stack_b);
  }
  ft_push("pa",stack_a, stack_b);
}

