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
    //ft_printlst(stack_a, stack_b);
    if (ft_check_sorted(&stack_a))
        ft_printf("already sorted\n");
    /*
    if (ac < 6)
        ft_little_sort(&stack_a, &stack_b);
       esle
       ft_bigsort(a, b);
    */
    ft_clstclear(&stack_a);
    ft_clstclear(&stack_b);
}
