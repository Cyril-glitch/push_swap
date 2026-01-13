#include  "../inc/push_swap.h"

static t_clist *ft_pretarget(t_clist **stack_a,t_clist **stack_b)
{
  t_clist *pretarget;
  pretarget = NULL;

  if((*stack_b)->content > ft_stack_max(*stack_a)->content)
  {
    (*stack_b)->target = ft_stack_min(*stack_a);
    return (NULL);
  }
  else
    pretarget = ft_stack_max(*stack_a);
  return (pretarget);
}

void  ft_target_a(t_clist **stack_a, t_clist **stack_b)
{
  t_clist *target;
  t_clist *current_a;
  t_clist *lap;

  target = ft_pretarget(stack_a, stack_b);
  current_a = *stack_a;
  lap = NULL;
  if (!target)
    return ;
  while (lap != *stack_a)
  {
    if ((current_a->content < target->content) && (current_a->content > (*stack_b)->content))
      target = current_a;
    (*stack_b)->target = target;
    current_a = current_a->next;
    lap = current_a;
  }
}
