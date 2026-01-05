#include  "../inc/push_swap.h"

int main(int  ac, char **av)
{

  if (ac < 2)
    ft_error(NULL,NULL,NULL);

  t_dlist *stack_a;
  t_dlist *stack_b;

  stack_a = NULL;
  stack_b = NULL;

  stack_a = ft_parser(ac, av);
  ft_printlst(stack_a);
  ft_swap("sa", &stack_a,&stack_b);
  ft_printlst(stack_a);

  /*
  if (ac < 10)
    ft_tinysort(a, b);
  esle 
    ft_bigsort(a, b);
  */
  ft_dlstclear(&stack_a);
}
