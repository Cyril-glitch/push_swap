#include  "../inc/push_swap.h"

static  void  ft_sa(t_dlist **stack)
{
  t_dlist *top1;
  t_dlist *top2;
  t_dlist *top1_prev;
  t_dlist *top2_next;

  if (!*stack || ft_stacksize(*stack) < 2)
    return ;

  top1 = *stack;
  top2 = (*stack)->next;
  top1_prev = top1->prev;
  top2_next = top2->next;

  top1->next = top2_next;
  top1->prev = top2;
  top2->next = top1;
  top2->prev = top1_prev;
  top1_prev->next = top2;
  top2_next->prev = top1;
  *stack = top2; 
}

void  ft_swap(const char *mode,t_dlist **stack_a ,t_dlist **stack_b)
{
  if (ft_strcmp(mode, "sa") == 0)
    ft_sa(stack_a);
  else if (ft_strcmp(mode, "sb") == 0)
    ft_sa(stack_b);
  else if (ft_strcmp(mode, "ss") == 0)
  {
    ft_sa(stack_a);
    ft_sa(stack_b);
  } 
}
