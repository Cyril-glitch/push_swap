#include  "../inc/push_swap.h"

static  void    ft_shifter(t_clist **head)
{
    t_clist *last;
    if  (!*head || (*head)->prev == *head)
        return ;
    last = (*head)->prev;
    *head = last;
}

void  ft_reverse(const char *mode, t_clist **stack_a, t_clist **stack_b)
{
    if (ft_strcmp(mode, "rra") == 0)
    {
        ft_shifter(stack_a);
        write(1, "rra\n", 4);
    }
    else if (ft_strcmp(mode, "rrb") == 0)
    {
        ft_shifter(stack_b);
        write(1, "rrb\n", 4);
    }
    else if (ft_strcmp(mode, "rrr") == 0)
    {
        ft_shifter(stack_a);
        ft_shifter(stack_b);
        write(1, "rrr\n", 4);
    }
}
