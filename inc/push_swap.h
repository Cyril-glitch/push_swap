
#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include  "../inc/libft.h"
# include  "../inc/ft_printf.h"

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif



typedef struct  s_dlist
{
  long     content;
  struct  s_dlist *prev;
  struct  s_dlist *next; 
} t_dlist;

//args_checker_utils
void ft_checkdigit(char **tab, t_dlist **new);
void ft_checkdup(char **tab, t_dlist **new);
void ft_check_overint(char **tab, t_dlist **new, long nbr);

//list utils
void  ft_printlst(t_dlist *stack);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlstnew(long content);
void	ft_dlstclear(t_dlist **lst);
int ft_stacksize(t_dlist *stack);

//recuperation et stockage des donnees
t_dlist *ft_parser(int  ac,char **av);
t_dlist *stack_init(int tab);

//fonctions generiques de tris
void  ft_swap(const char *mode,t_dlist **stack_a, t_dlist **stack_b);
void  ft_push(const char *mode,t_dlist **stack_a, t_dlist **stack_b);
void  ft_rotate(const char *mode,t_dlist **stack_a, t_dlist **stack_b);
void  ft_reverse(const char *mode,t_dlist **stack_a, t_dlist **stack_b);

//fonctions principal de tris
void  ft_tinysort(t_dlist stack);
void  ft_bigsort(t_dlist stack);

//exit and clean
void  ft_error(char **tab, t_dlist **stack_a, t_dlist **stack_b);

#endif
