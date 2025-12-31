#include  "../inc/push_swap.h"

void  ft_printlst(t_dlist *stack)
{
  int lap;
  t_dlist *current;

  lap = 0;
  current = stack; 
  while (!lap)
  {
    ft_printf("%d-->",current->content);
    current = current->next;
    if (current == stack)
      lap++;
  }
  ft_printf("NULL");
}

t_dlist	*ft_dlstnew(long content)
{
	t_dlist	*node;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	if (!lst || !new)
		return ;
	if (*lst && !(*lst)->prev)
	{
    new->next = *lst;
    new->prev = *lst;
    (*lst)->prev = new;
    (*lst)->next = new;
	}
	if (*lst && (*lst)->prev)
  {
    new->next = *lst;
    new->prev = (*lst)->prev;
    (*lst)->prev->next = new;
    (*lst)->prev = new;
  }
	else
		*lst = new;
}

int ft_stacksize(t_dlist *stack)
{
  int lap;
  int i;
  t_dlist *current;

  lap = 0;
  i = 0;
  current = stack; 
  while (!lap)
  {
    current = current->next;
    i++;
    if (current == stack)
      lap++;
  }
  return (i);
}

void	ft_dlstclear(t_dlist **lst)
{
  int i;
  int size;
  t_dlist *current;

  i = 0;
  size = ft_stacksize(*lst);
  while (i < size)
  {
    current = *lst;
    *lst = (*lst)->next;
    free(current);
    i++;
  }
}
