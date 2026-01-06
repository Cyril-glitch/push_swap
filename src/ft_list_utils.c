#include  "../inc/push_swap.h"

void  ft_printlst(t_clist *stack_a, t_clist *stack_b)
{
  t_clist *current_a;
  t_clist *current_b;
  size_t  size_a;
  size_t  size_b;
  size_t  size;
  size_t  i;


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
      ft_printf("[%d]",current_a->content);
      current_a = current_a->next;
    }
    else
      write(1, "   ",3);
    write(1, "  ",2);
    if (i < size_b)
    {
      ft_printf("[%d]",current_b->content);
      current_b = current_b->next;
    }
    write(1, "\n", 1);
    i++;
  }
  ft_putstr(" a    b \n\n");
}

t_clist	*ft_clstnew(long content)
{
	t_clist	*node;

	node = malloc(sizeof(t_clist));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_clstadd_back(t_clist **lst, t_clist *new)
{
	if (!lst || !new)
    ft_error(NULL,lst,NULL);
	if (*lst)
  {
    new->next = *lst;
    new->prev = (*lst)->prev;
    (*lst)->prev->next = new;
    (*lst)->prev = new;
  }
	else
  {
		*lst = new;
    new->next = new;
    new->prev = new;
  }
}


int ft_stacksize(t_clist *stack)
{
  int lap;
  int i;
  t_clist *current;

  if (!stack)
    return (0);
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

void	ft_clstclear(t_clist **lst)
{
  int i;
  int size;
  t_clist *current;

  if (!lst)
    return ;
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
