#include  "../inc/push_swap.h"

static  void    ft_shifter(t_clist **head)
{
    t_clist *second;
    if  (!*head || (*head)->prev == *head)
        return ;
    second = (*head)->next;
    *head = second;
}

void  ft_rotate(const char *mode, t_clist **stack_a, t_clist **stack_b)
{
    if (ft_strcmp(mode, "ra") == 0)
    {
        ft_shifter(stack_a);
        write(1, "ra\n", 3);
    }
    else if (ft_strcmp(mode, "rb") == 0)
    {
        ft_shifter(stack_b);
        write(1, "rb\n", 3);
    }
    else if (ft_strcmp(mode, "rr") == 0)
    {
        ft_shifter(stack_a);
        ft_shifter(stack_b);
        write(1, "rr\n", 3);
    }
}
