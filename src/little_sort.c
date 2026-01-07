#include  "../inc/push_swap.h"

void static ft_little_three(t_clist **stack_a, t_clist **stack_b, size_t size)
{
    if (size == 2)
        ft_swap("sa",stack_a, stack_b);
    if (size == 3)
    {
        if((*stack)->content < (*stack)->next->content)
        {
            ft_rotate("ra",stack_a, stack_b);
            ft_swap("sa",stack_a, stack_b);
            ft_reverse("rra",stack_a, stack_b);
        }
        else
            ft_reverse("rra",stack_a, stack_b);
    }
}
void    ft_little_sort(t_clist **stack_a, t_clist **stack_b)
{
    size_t  size;

    size = ft_stacksize(*stack_a);
    if (size < 4)
        ft_little_three(stack_a, stack_b, size);
    if (size == 4)
    {

    }
    if (size == 5)
    {

    }

}
