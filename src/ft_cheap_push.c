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

static  void  ft_iterotate(t_clist **stack_a, t_clist **stack_b, t_moves *mv)
{
  while (mv->ra)
  {
    ft_rotate("ra",stack_a, stack_b);
    mv->ra--;
  }
  while (mv->rb)
  {
    ft_rotate("rb",stack_a, stack_b);
    mv->rb--;
  }
  while (mv->rr)
  {
    ft_rotate("rr",stack_a, stack_b);
    mv->rr--;
  }
}

static  void  ft_itereverse(t_clist **stack_a, t_clist **stack_b, t_moves *mv)
{
  while (mv->rra)
  {
    ft_reverse("rra",stack_a, stack_b);
    mv->rra--;
  }
  while (mv->rrb)
  {
    ft_reverse("rrb",stack_a, stack_b);
    mv->rrb--;
  }
  while (mv->rrr)
  {
    ft_reverse("rrr",stack_a, stack_b);
    mv->rrr--;
  }
}

static  void  ft_stratpusher(t_clist **stack_a, t_clist **stack_b, t_moves *mv)
{
  ft_iterotate(stack_a, stack_b, mv);
  ft_itereverse(stack_a, stack_b, mv);
  ft_push("pb", stack_a, stack_b);
}

void ft_cheap_push(t_clist **stack_a, t_clist **stack_b, int size, int size_b)
{
  t_clist *cheapest;
  t_moves *mv;

  cheapest = ft_cheaper(*stack_a);
  mv = ft_loadmoves(cheapest, size, size_b);
  if (!mv)
    ft_error(NULL,stack_a, stack_b);
  ft_stratpusher(stack_a, stack_b, mv);
  cheapest->target = NULL;
  cheapest->cost = -1;
  cheapest->strat = -1;
}
