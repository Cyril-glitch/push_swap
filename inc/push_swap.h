
#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include  "../inc/libft.h"
# include  "../inc/ft_printf.h"

typedef struct  s_dlist
{
  long     content;
  struct  s_dlist *prev;
  struct  s_dlist *next; 
} t_dlist;

//list utils
void  ft_printlst(t_dlist *stack);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlstnew(long content);
void	ft_dlstclear(t_dlist **lst, void (*del)(void*));
void	ft_dlstdelone(t_dlist *lst, void (*del)(void*));

//recuperation et stockage des donnees
t_dlist *ft_parser(int  ac,char **av);
t_dlist *stack_init(int tab);

//fonctions generiques de tris
void  ft_swap(const char mode,t_dlist stack);
void  ft_push(const char mode,t_dlist stack);
void  ft_rotate(const char mode,t_dlist stack);
void  ft_reverse(const char mode,t_dlist stack);

//fonctions principal de tris
void  ft_tinysort(t_dlist stack);
void  ft_bigsort(t_dlist stack);

//clean
void  ft_error(t_dlist **stack_a, t_dlist **stack_b);

#endif
