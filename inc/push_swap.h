
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



typedef struct  s_clist
{
  long     content;
  int     index;
  struct  s_clist *prev;
  struct  s_clist *next; 
  struct  s_clist *target;
  int     cost;
  int     strat;
} t_clist;

typedef struct  s_cost
{
  int ra;
  int rb;
  int rra;
  int rrb;
  int rr;
  int rrr;
} t_cost;


//args_checker_utils
void ft_checkdigit(char **tab, t_clist **new);
void ft_checkdup(char **tab, t_clist **new);
void ft_check_overint(char **tab, t_clist **new, long nbr);
int  ft_check_sorted(t_clist **stack_a);
void  ft_error(char **tab, t_clist **stack_a, t_clist **stack_b);

//list utils
void  ft_printlst(t_clist *stack_a, t_clist *stack_b);
void	ft_clstadd_back(t_clist **head, t_clist *new);
void	ft_clstadd_front(t_clist **head, t_clist *new);
t_clist	*ft_clstnew(long content);
void	ft_clstclear(t_clist **lst);
int ft_stacksize(t_clist *stack);
void  ft_freecnode(t_clist **lst);

//recuperation et stockage des donnees
t_clist *ft_parser(int  ac,char **av);
t_clist *stack_init(int tab);

//fonctions generiques de tris
void  ft_swap(const char *mode,t_clist **stack_a, t_clist **stack_b);
void  ft_push(const char *mode,t_clist **stack_a, t_clist **stack_b);
void  ft_rotate(const char *mode,t_clist **stack_a, t_clist **stack_b);
void  ft_reverse(const char *mode,t_clist **stack_a, t_clist **stack_b);

//fonctions principal de tris
void  ft_little_sort(t_clist **stack_a, t_clist **stack_b);
void  ft_big_sort(t_clist **stack_a, t_clist **stack_b);

//detection de min et max
t_clist *ft_stack_min(t_clist *stack);
t_clist *ft_stack_max(t_clist *stack);

//target choice
void  ft_target(t_clist **stack_a, t_clist **stack_b);

//cost
t_cost *ft_init_cost(void);

//strat
int ft_strat_0(t_clist *node, t_cost *cost);
int ft_strat_1(t_clist *node, t_cost *cost, int size);
int ft_strat_2(t_clist *node, t_cost *cost, int size);
int ft_strat_3(t_clist *node, t_cost *cost, int size);

#endif
