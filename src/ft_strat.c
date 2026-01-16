
#include  "../inc/push_swap.h"

int ft_strat_0(t_clist *node)
{
  int ra;
  int rb;

  ra = node->index;
  rb = node->target->index;

  if (ra > rb)
    return (ra);
  return  (rb);
}

int ft_strat_1(t_clist *node, int size, int size_b)
{
  int rra;
  int rrb;

  if (node->index == 0)
    rra = 0;
  else
    rra = size - node->index;
  if (node->target->index == 0)
    rrb = 0;
  else
    rrb = size_b - node->target->index;
  if (rra > rrb)
    return (rra);
  return (rrb);
}

int ft_strat_2(t_clist *node, int size_b)
{
  int ra;
  int rrb;

  ra = node->index;
  if (node->target->index == 0)
    rrb = 0;
  else
    rrb = size_b - node->target->index;
  return (ra + rrb);
}

int ft_strat_3(t_clist *node, int size)
{
  int rb;
  int rra;

  rb = node->target->index;
  if (node->index == 0)
    rra = 0;
  else
    rra = size - node->index;
  return (rb + rra);
}
