#include  "../inc/push_swap.h"

static void  ft_index(t_clist **stack)
{
  t_clist *current;
  t_clist *lap;
  int i;

  if (!*stack)
    return ;
  i = 0;
  current = *stack;
  lap = NULL;
  while (lap != *stack)
  {
    current->index = i;
    current = current->next;
    lap = current;
    i++;
  }
}

static void  ft_init(t_clist **stack_a, t_clist **stack_b)
{
  ft_push("pb",stack_a, stack_b);
  ft_push("pb",stack_a, stack_b);
  if (*stack_b < (*stack_b)->next)
    ft_swap("sb", stack_a, stack_b);
}

void  ft_big_sort(t_clist **stack_a, t_clist **stack_b)
{
 // t_clist *cheapest;
  ft_init(stack_a, stack_b);
  ft_index(stack_a);
  ft_index(stack_b);
  ft_target(stack_a, stack_b);
  ft_cost(stack_a, )

  /*
  while ((*stack_a)->next->next->next != *stack_a)
  {
    ft_index(stack_a);
    ft_index(stack_b);
    ft_target(stack_a, stack_b);
    //cheapest = ft_cost(stack_a);
    //ft_cheap_push(cheapest);
  }
  ft_little_sort(stack_a);
  while (*stack_b)
    ft_push("pb",stack_a, stack_b);
  */
}
