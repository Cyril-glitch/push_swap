#include  "../inc/push_swap.h"

t_cost *ft_init_cost(void)
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

static  void  ft_onecost(t_clist *node, t_cost *cost, int size)
{
  int i;
  int tab[4];
  int mincost;

  tab[0] = ft_strat_0(node, t_cost, size);
  tab[1] = ft_strat_1(node, t_cost, size);
  tab[2] = ft_strat_2(node, t_cost, size);
  tab[3] = ft_strat_3(node, t_cost, size);
  i = 0;
  mincost = tab[0];
  while (i < 3)
  {
    if (tab[i] > tab[i + 1])
    mincost = tab[i + 1] 
    i++;
  }
  node->cost = mincost;
  node->strat = i;
}

void  ft_cost(t_clist **stack_a, t_cost *cost, int size)
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
