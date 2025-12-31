#include  "push_swap.h"
#include  <unistd.h>

int main(int  ac, char **av)
{
  if (ac < 1)
    return 0;

  t_dlist *stack_a;
  t_dlist *stack_b;

  stack_a = NULL;
  stack_b = NULL;

  stack_a = ft_parser(ac, av);
  ft_printlst(stack_a);


  /*
  if (ac < 10)
    ft_tinysort(a, b);
  esle 
    ft_bigsort(a, b);
  */
}
