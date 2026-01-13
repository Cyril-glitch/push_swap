#include  "../inc/push_swap.h"

static t_clist *ft_pretarget(t_clist **stack_a,t_clist **stack_b)
{
  t_clist *pretarget;
  pretarget = NULL;

  if((*stack_a)->content < ft_stack_min(*stack_b)->content)
  {
    (*stack_a)->target = ft_stack_max(*stack_b);
    return (NULL);
  }
  else
    pretarget = ft_stack_min(*stack_b);
  return (pretarget);
}

static void  ft_onetarget(t_clist **node, t_clist **stack_b)
{
  t_clist *target;
  t_clist *current_b;
  t_clist *lap;

  target = ft_pretarget(node, stack_b);
  current_b = *stack_b;
  lap = NULL;
  if (!target)
    return ;
  while (lap != *stack_b)
  {
    if ((current_b->content > target->content) && (current_b->content < (*node)->content))
      target = current_b;
    (*node)->target = target;
    current_b = current_b->next;
    lap = current_b;
  }
}

void  ft_target_b(t_clist **stack_a, t_clist **stack_b)
{
  t_clist *tmp;
  t_clist *lap;

  tmp = *stack_a;
  lap = NULL;
  while (lap != tmp)
  {
    ft_onetarget(stack_a, stack_b);
    *stack_a = (*stack_a)->next;
    lap = *stack_a;
  }
}
