#include  "../inc/push_swap.h"

void  ft_printlst(t_clist *stack_a, t_clist *stack_b)
{
  t_clist *current_a;
  t_clist *current_b;
  int target_a;
  int target_b;
  size_t  size_a;
  size_t  size_b;
  size_t  size;
  size_t  i;
  int res;


  target_a = 0;
  target_b = 0;
  current_a = stack_a;
  current_b = stack_b;
  size_a = ft_stacksize(stack_a);
  size_b = ft_stacksize(stack_b);
  i = 0;
  if (size_a > size_b)
    size = size_a;
  else
    size = size_b;
  while (i < size)
  {
    if (i < size_a)
    {
      if (current_a->target)
        target_a = current_a->target->content;
      res = ft_printf("[%d] = %d [targ = %d][cost = %d][strat = %d]",current_a->index, current_a->content, target_a,current_a->cost, current_a->strat);
      current_a = current_a->next;
    }
    else
      write(1, "                                                                               ",res);
    write(1, "     ",5);
    if (i < size_b)
    {
      if (current_b->target)
        target_b = current_b->target->content;
      ft_printf("[%d] = %d [targ = %d][cost = %d][strat = %d]",current_b->index, current_b->content, target_b,current_b->cost,current_b->strat);
      current_b = current_b->next;
    }
    write(1, "\n", 1);
    i++;
  }
  ft_printf("\n---------------------------------------    ----------------------------------------------");
  ft_putstr("\n\n                   A                                               B \n\n");
}

t_clist	*ft_clstnew(long content)
{
	t_clist	*new;

	new = malloc(sizeof(t_clist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = new;
	new->prev = new;
  new->index = -1;
  new->target = NULL;
  new->cost = -1;
  new->strat = -1;
	return (new);
}

void	ft_clstadd_front(t_clist **head, t_clist *new)
{
    t_clist *last;
    if (!new)
        exit(EXIT_FAILURE);
    if (*head)
    {
        last = (*head)->prev;
        new->next = (*head);
        new->prev = last;
        last->next = new;
        (*head)->prev = new;
        *head = new;
    }
    else
    {
        *head = new;
        new->next = new;
        new->prev = new;
    }
}

void	ft_clstadd_back(t_clist **head, t_clist *new)
{
    if (!head || !new)
        ft_error(NULL,head,NULL);
    if (*head)
    {
        new->next = *head;
        new->prev = (*head)->prev;
        (*head)->prev->next = new;
        (*head)->prev = new;
    }
    else
    {
        *head = new;
        new->next = new;
        new->prev = new;
    }
}


int ft_stacksize(t_clist *head)
{
  int i;
  t_clist *current;

  if (!head)
    return (0);
  i = 1;
  current = head; 
  while (current->next != head)
  {
    current = current->next;
    i++;
  }
  return (i);
}

void	ft_clstclear(t_clist **head)
{
  int i;
  int size;
  t_clist *current;

  if (!head)
    return ;
  i = 0;
  size = ft_stacksize(*head);
  while (i < size)
  {
    current = *head;
    *head = (*head)->next;
    free(current);
    i++;
  }
}
