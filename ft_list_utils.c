void  printlst(t_dlist *stack)
{
  int i;
  t_dlist current;

  i = 0;
  current = stack; 
  while (current)
  {
    ft_printf("%d-->",current->value);
    current = current->next;
  }
  ft_printf("NULL");
}
