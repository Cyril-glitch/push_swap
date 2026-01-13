#include  "../inc/push_swap.h"

void ft_upapushb(t_clist **stack_a, t_clist **stack_b, int size)
{
  int ra;
  int rra;

  ra = (*stack_b)->target->index;
  rra = size - (*stack_b)->target->index;
  if (ra > rra)
  {
    while(rra)
    {
      ft_reverse("rra", stack_a, stack_b);
      rra--;
    }
  }
  else 
  {
    while(ra)
    {
      ft_rotate("ra", stack_a, stack_b);
      ra--;
    }
  }
  ft_push("pa",stack_a, stack_b);
}

