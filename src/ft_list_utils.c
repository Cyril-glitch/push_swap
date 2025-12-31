#include  "../inc/push_swap.h"

void  ft_printlst(t_dlist *stack)
{
  int i;
  t_dlist *current;

  i = 0;
  current = stack; 
  while (current)
  {
    ft_printf("%d-->",current->content);
    current = current->next;
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

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
    (*lst)->prev = new;
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

void	ft_dlstclear(t_dlist **lst, void (*del)(void*))
{
	t_dlist	*todel;

	if (!lst || !del)
		return ;
	todel = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
    free(*lst);
		todel = *lst;
	}
}
