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

static void ft_phase_b(t_clist **stack_a, t_clist **stack_b);
{
  int size;
  int size_b;

  size = 0;
  size_b = 0;
  ft_init(stack_a, stack_b);
  ft_index(stack_a);
  ft_index(stack_b);
  while ((*stack_a)->prev->index != 2)
  {
    size = (*stack_a)->prev->index + 1;
    size_b = (*stack_b)->prev->index + 1;
    ft_target(stack_a, stack_b);
    ft_cost(stack_a, size, size_b);
    ft_cheap_push(stack_a, stack_b, size, size_b);
    ft_index(stack_a);
    ft_index(stack_b);
  }
}

static void ft_phase_a(t_clist **stack_a, t_clist **stack_b);
{
  int size;
  int size_b;

  size = 0;
  size_b = 0;
  ft_index(stack_a);
  ft_index(stack_b);
  while (*stack_b)
  {
    size = (*stack_a)->prev->index + 1;
    size_b = (*stack_b)->prev->index + 1;
    ft_target(stack_a, stack_b);
    ft_cost(stack_a, size, size_b);
    ft_cheap_push(stack_a, stack_b, size, size_b);
    ft_index(stack_a);
    ft_index(stack_b);
  }
}

void  ft_big_sort(t_clist **stack_a, t_clist **stack_b)
{
 // t_clist *cheapest;
  int size;
  int size_b;

  size = 0;
  size_b = 0;
  ft_init(stack_a, stack_b);
  ft_index(stack_a);
  ft_index(stack_b);
  while ((*stack_a)->prev->index != 2)
  {
    size = (*stack_a)->prev->index + 1;
    size_b = (*stack_b)->prev->index + 1;
    ft_target(stack_a, stack_b);
    ft_cost(stack_a, size, size_b);
    ft_cheap_push(stack_a, stack_b, size, size_b);
    ft_index(stack_a);
    ft_index(stack_b);
  }
  /*
  ft_little_sort(stack_a);
  while (*stack_b)
    ft_push("pb",stack_a, stack_b);
  */
}
