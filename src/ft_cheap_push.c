#include  "../inc/push_swap.h"

static t_clist *ft_cheaper(t_clist *stack)
{
  t_clist *compared;
  t_clist *min;

  if (!stack)
    return (NULL);
  min = stack;
  compared = stack->next; 
  while (compared != stack)
  {
    if (min->cost > compared->cost)
      min = compared;
    compared = compared->next;
  }
  return (min);
}

void ft_cheap_push(t_clist **stack_a, t_clist **stack_b)
{
  t_clist *cheapest;
  t_cost *moves;

  moves = ft_init_cost();
  cheapest = ft_cheaper(*stack_a);
  if (!cheapest)
    return ;
  ft_load_moves(moves, cheapest->strat);
  ft_moves(moves, stack_a, stack_b);
}
