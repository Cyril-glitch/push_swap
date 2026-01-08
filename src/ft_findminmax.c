#include  "../inc/push_swap.h"

static int ft_ismin(long  value, t_clist  *stack)
{
  t_clist *current;
  t_clist *lap;

  if (!stack)
    return (0);
  current = stack;
  lap = NULL;
  while (lap != stack)
  {
    if (value > current->content)
      return (0);
    current = current->next;
    lap = current;
  }
  return (1);
}

static int ft_ismax(long  value, t_clist  *stack)
{
  t_clist *current;
  t_clist *lap;

  if (!stack)
    return (0);
  current = stack;
  lap = NULL;
  while (lap != stack)
  {
    if (value < current->content)
      return (0);
    current = current->next;
    lap = current;
  }
  return (1);
}

t_clist *ft_stack_min(t_clist *stack)
{
  t_clist *current;
  t_clist *last;

  if (!stack)
    return (NULL);
  current = stack; 
  last = stack->prev;
  while (current != last)
  {
    if (ft_ismin(current->content, stack))
      return (current);
    current = current->next;
  }
  return (last);
}

t_clist *ft_stack_max(t_clist *stack)
{
  t_clist *current;
  t_clist *last;

  if (!stack)
    return (NULL);
  current = stack; 
  last = stack->prev;
  while (current != last)
  {
    if (ft_ismax(current->content, stack))
      return (current);
    current = current->next;
  }
  return (last);
}
