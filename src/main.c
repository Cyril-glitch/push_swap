#include  "../inc/push_swap.h"

int main(int  ac, char **av)
{

  if (ac < 2)
    ft_error(NULL,NULL,NULL);

  t_clist *stack_a;
  t_clist *stack_b;

  stack_a = NULL;
  stack_b = NULL;

  stack_a = ft_parser(ac, av);

  ft_printlst(stack_a, stack_b);
  ft_swap("sa", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_push("pb", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_push("pb", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_push("pb", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_swap("sb", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_push("pb", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_push("pa", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_push("pa", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_swap("sb", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_swap("pb", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);

  ft_swap("pb", &stack_a, &stack_b);
  ft_printlst(stack_a, stack_b);
      /*
  if (ac < 10)
    ft_tinysort(a, b);
  esle 
    ft_bigsort(a, b);
  */
  ft_clstclear(&stack_a);
}
