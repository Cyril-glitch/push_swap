#include  "../inc/push_swap.h"

void  ft_upmin(t_clist **stack_a, t_clist **stack_b)
{
  t_clist *min;
  int ra;
  int rra;
  int size;

  size = (*stack_a)->prev->index + 1;
  min = ft_stack_min(*stack_a);
  ra = (*stack_a)->target->index;
  rra = size - (*stack_a)->target->index;

  if (ra > rra)
  {
    while(*stack_a != min)
      ft_reverse("rra", stack_a, stack_b);
  }
  else
  {
    while(*stack_a != min)
      ft_rotate("ra", stack_a, stack_b);
  }
}
