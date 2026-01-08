#include  "../inc/push_swap.h"

void static ft_sort_two(t_clist **stack_a, t_clist **stack_b)
{
  if((*stack_a)->content > (*stack_a)->next->content)
    ft_swap("sa",stack_a, stack_b);
}

void static ft_sort_three(t_clist **stack_a, t_clist **stack_b)
{
  t_clist *first;
  t_clist *second;
  t_clist *max;



  first = *stack_a;
  second = (*stack_a)->next;
  max = ft_stack_max(*stack_a);


  if (first == max)
    ft_rotate("ra",stack_a, stack_b);
  else if (second == max)
    ft_reverse("rra", stack_a, stack_b);
  ft_sort_two(stack_a, stack_b);
}

void static ft_sort_four(t_clist **stack_a, t_clist **stack_b)
{
  t_clist *second;
  t_clist *third;
  t_clist *fourth;
  t_clist *min;

  second = (*stack_a)->next;
  third = second->next;
  fourth = third->next;
  min = ft_stack_min(*stack_a);

  if (second == min)
    ft_rotate("ra",stack_a, stack_b);
  else if (third == min)
  {
    ft_rotate("ra", stack_a, stack_b);
    ft_rotate("ra", stack_a, stack_b); 
  }
  else if (fourth == min)
    ft_reverse("rra", stack_a, stack_b);
  ft_push("pb",stack_a,stack_b);
  ft_sort_three(stack_a, stack_b);
  ft_push("pa",stack_a,stack_b);
}

void static ft_sort_five(t_clist **stack_a, t_clist **stack_b)
{
  t_clist *second;
  t_clist *third;
  t_clist *fourth;
  t_clist *fifth;
  t_clist *min;

  second = (*stack_a)->next;
  third = second->next;
  fourth = third->next;
  fifth = fourth->next;

  min = ft_stack_min(*stack_a);
  if (second == min)
    ft_rotate("ra",stack_a, stack_b);
  else if (third == min)
  {
    ft_rotate("ra", stack_a, stack_b);
    ft_rotate("ra", stack_a, stack_b); 
  }
  else if (fourth == min)
  {
    ft_reverse("rra", stack_a, stack_b);
    ft_reverse("rra", stack_a, stack_b);
  }
  else if (fifth == min)
    ft_reverse("rra", stack_a, stack_b);
  ft_push("pb",stack_a,stack_b);
  ft_sort_four(stack_a, stack_b);
  ft_push("pa",stack_a,stack_b);
}

void    ft_little_sort(t_clist **stack_a, t_clist **stack_b)
{
  size_t  size;

  size = ft_stacksize(*stack_a);
  if (size == 2)
    ft_sort_two(stack_a, stack_b);
  else if (size == 3)
    ft_sort_three(stack_a, stack_b);
  else if (size == 4)
    ft_sort_four(stack_a, stack_b);
  else if (size == 5)
    ft_sort_five(stack_a, stack_b);
}
