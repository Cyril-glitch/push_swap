#include  "../inc/push_swap.h"

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

void  ft_freecnode(t_clist **lst)
{
  t_clist *todel;
  todel = *lst;
  if (!lst)
    return ;
  (*lst)->next->prev = (*lst)->prev;
  (*lst)->prev->next = (*lst)->next;
  (*lst) = (*lst)->next;
  free(todel);
  todel = NULL;
}

