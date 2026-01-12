
#include  "../inc/push_swap.h"

int ft_strat_0(t_clist *node, t_cost *cost)
{
  int totalcost;

  cost->ra = node->index;
  cost->rb = node->target->index;
  if (cost->ra > cost->rb)
    cost->rr = cost->ra - cost->rb; 
  else if (cost->ra == cost->rb)
    cost->rr = cost->ra; 
  else 
    cost->rr = cost->rb - cost->ra;
  totalcost = (ra + rb) - rr;
  return  (totalcost);
}


int ft_strat_1(t_clist *node, t_cost *cost, int size)
{

  int totalcost;

  cost->rra = node->index - size;
  cost->rrb = node->target->index - size;
  if (cost->rra > cost->rrb)
    cost->rrr = cost->rra - cost->rrb; 
  else if (cost->rra == cost->rrb)
    cost->rrr = cost->rra; 
  else 
    cost->rrr = cost->rrb - cost->rra;
  totalcost = (rra + rrb) - rrr; 
  return  (totalcost);
}

int ft_strat_2(t_clist *node, t_cost *cost, int size)
{
  int totalcost;

  cost->ra = node->index;
  cost->rrb = node->target->index - size;
  totalcost = ra + rrb;
  return (totalcost);
}

int ft_strat_3(t_clist *node, t_cost *cost, int size)
{
  int totalcost;

  cost->rra = node->index;
  cost->rb = node->target->index - size;
  totalcost = rra + rb;
  return (totalcost);
}
