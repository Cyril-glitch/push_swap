
#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

#include  "/ft_printf/ft_printf.h"
#include  "/libft/libft.h"
#include  <stdlib.h>
#include  <fcntl.h>
#include  <unistd.h>

typedef struct  s_dlist
{
  int value;
  struct  t_dlist *prev;
  struct  t_dlist *next; 
} t_dlist;

//list utils
void  printlst(t_dlist *stack);

//recuperation et stockage des donnees
t_dlist *ft_parser(int  ac,char av);
t_dlist *stack_init(int tab);

//fonctions generiques de tris
void  ft_swap(const char mode,t_dlist stack);
void  ft_push(const char mode,t_dlist stack);
void  ft_rotate(const char mode,t_dlist stack);
void  ft_reverse(const char mode,t_dlist stack);

//fonctions principal de tris
void  ft_tinysort(t_dlist stack);
void  ft_bigsort(t_dlist stack);
