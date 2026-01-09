#include  "../inc/push_swap.h"

static  t_cost *ft_init_cost(void)
{
  t_cost *new = malloc(sizeof(t_cost));
  if (!new)
    exit(EXIT_FAILURE);
  new->ra = 0;
  new->rb = 0;
  new->rra = 0;
  new->rrb = 0;
  new->rr = 0;
  new->rrr = 0;
}

static  int *ft_strat_1(t_clist *node, t_cost *cost)
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
  totalcost = ((ra - rr) + (rb - rr)) + rr; 
}
static  void ft_strat_2(t_clist **stack_a)
{

}
static  void ft_strat_3(t_clist **stack_a)
{

}

static  void ft_strat_4(t_clist **stack_a)
{

}

static  void  ft_onecost(t_clist **stack_a)
{

}

void  ft_cost(t_clist **stack_a, t_clist **stack_b)
{
  t_clist *tmp;
  t_clist *lap;

  tmp = *stack_a;
  lap = NULL;
  while (lap != tmp)
  {
    ft_onecost(stack_a, stack_b);
    *stack_a = (*stack_a)->next;
    lap = *stack_a;
  }
}
