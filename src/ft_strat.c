
#include  "../inc/push_swap.h"

int ft_strat_0(t_clist *node)
{
  int totalcost;
  int ra;
  int rb;
  int rr;

  ra = node->index;
  rb = node->target->index;
  rr = 0;
  if (ra == 0)
    return (rb);
  if (rb == 0)
    return (ra);
  if (ra > rb)
    rr = rb; 
  else if (ra < rb)
    rr = ra;
  else if (ra == rb)
    rr = ra; 
  totalcost = (ra + rb) - rr;
  return  (totalcost);
}

int ft_strat_1(t_clist *node, int size, int size_b)
{
  int totalcost;
  int rra;
  int rrb;
  int rrr;

  rra = size - node->index;
  rrb = size_b - node->target->index;
  rrr = 0;
  if (rra == 0)
    return (rrb);
  if (rrb == 0)
    return (rra);
  if (rra > rrb)
    rrr = rrb; 
  else if (rra < rrb)
    rrr = rra;
  else if (rra == rrb)
    rrr = rra; 
  totalcost = (rra + rrb) - rrr;
  return  (totalcost);
}

int ft_strat_2(t_clist *node, int size_b)
{
  int totalcost;
  int ra;
  int rrb;

  ra = node->index;
  rrb = size_b - node->target->index;
  totalcost = ra + rrb;
  return (totalcost);
}

int ft_strat_3(t_clist *node, int size)
{
  int totalcost;
  int rra;
  int rb;

  rra = size - node->index;
  rb = node->target->index ;
  totalcost = rra + rb;
  return (totalcost);
}
