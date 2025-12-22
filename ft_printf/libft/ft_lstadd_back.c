/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:52:40 by cycolonn          #+#    #+#             */
/*   Updated: 2025/11/17 16:54:10 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
   void  ft_putlst(t_list  *lst)
   {
   t_list  *current = lst;
   while(current)
   {
   printf("%s",(char*)current->content);
   current = current->next;
   }
   }
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

/*
   int main()
   {
   t_list  *lst = NULL;
   ft_lstadd_front(&lst,ft_lstnew("1"));
   ft_lstadd_front(&lst,ft_lstnew("2"));
   ft_lstadd_front(&lst,ft_lstnew("3"));

   ft_lstadd_back(&lst,ft_lstnew("1"));
   ft_lstadd_back(&lst,ft_lstnew("2"));
   ft_lstadd_back(&lst,ft_lstnew("3"));


   ft_putlst(lst);
   write(1, "\n", 1); 
   }
 */
