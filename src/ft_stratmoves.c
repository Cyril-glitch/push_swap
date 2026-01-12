#include  "../inc/push_swap.h"

static t_moves *ft_init_moves(void)
{
  t_moves *new = malloc(sizeof(t_cost));
  if (!new)
    exit(EXIT_FAILURE);
  new->ra = 0;
  new->rb = 0;
  new->rra = 0;
  new->rrb = 0;
  new->rr = 0;
  new->rrr = 0;
}

static void ft_strat_moves_0(t_clist *cheapest, t_moves *mv)
{
  mv->ra = node->index;
  mv->rb = node->target->index;
  mv->rr = 0;
  if (mv->ra > mv->rb)
    mv->rr = mv->rb; 
  else if (mv->ra < mv->rb)
    mv->rr = mv->ra;
  else if (mv->ra == mv->rb)
    mv->rr = mv->ra; 
  mv->ra -= mv->rr;
  mv->rb -= mv->rr;
}

static void ft_strat_moves_1(t_clist *cheapest,t_moves *mv, int size, int size_b)
{
  mv->rra = size - node->index;
  mv->rrb = size_b - node->target->index;
  mv->rrr = 0;
  if (mv->rra > mv->rrb)
    mv->rrr = mv->rrb; 
  else if (mv->rra < mv->rrb)
    mv->rrr = mv->rra;
  else if (mv->rra == mv->rrb)
    mv->rrr = mv->rra; 
  mv->rra -= mv->rrr;
  mv->rrb -= mv->rrr;
}

static void ft_strat_moves_23(t_clist *cheapest, t_moves *mv, int size,int size_b)
{
  if (cheapest->strat == 2)
  {
    mv->ra = node->index;
    mv->rrb = size_b - node->target->index;
  }
  else if(cheapest->strat == 3)
  {
    mv->rra = size - node->index;
    mv->rb = node->target->index ;
  }
}

void ft_loadmoves(t_clist *cheapest, t_moves *mv)
{
  if (cheapest->strat == 0)
    ft_strat_moves_0(cheapest, mv);
  if (cheapest->strat == 1)
    ft_strat_moves_1(cheapest, mv, size , size_b);
  else
    ft_strat_moves_23(cheapest, mv, size, size_b);
}

