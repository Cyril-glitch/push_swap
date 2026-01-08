#include  "../inc/push_swap.h"

static  t_clist *ft_cutnode(t_clist **head)
{
  t_clist *last;
  t_clist *second;
  t_clist *cutted;

  if (!*head)
      return (NULL);
  if ((*head) == (*head)->next)
  {
    cutted = *head;
    *head = NULL;
    return (cutted);
  }
  last = (*head)->prev;
  second = (*head)->next;
  last->next = second;
  second->prev = last;
  cutted = *head;
  *head = second;
  cutted->next = cutted;
  cutted->prev = cutted;
  return (cutted);
}

static  void ft_pusher(t_clist **dst, t_clist **src)
{
  if (!*src)
    return ;
  ft_clstadd_front(dst, ft_cutnode(src));
}

void  ft_push(const char *mode, t_clist **stack_a, t_clist **stack_b)
{
  if (ft_strcmp(mode, "pa") == 0)
  {
    ft_pusher(stack_a, stack_b);
    write(1, "pa\n", 3);
  }
  else if (ft_strcmp(mode, "pb") == 0)
  {
    ft_pusher(stack_b, stack_a);
    write(1, "pb\n", 3);
  }
}
