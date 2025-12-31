#include  "push_swap.h"
#include  "libft/libft.h"
#include  "ft_printf/ft_printf.h"


void  ft_error(t_dlist **stack_a, t_dlist **stack_b)
{
  ft_dlstclear(stack_a, free);
  ft_dlstclear(stack_b, free);

  ft_printf("ERROR\n");
  exit(EXIT_FAILURE);
}
