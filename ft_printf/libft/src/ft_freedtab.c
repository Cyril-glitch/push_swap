#include "../inc/libft.h"

void  ft_freedtab(void *t)
{
  size_t  i;
  size_t  size;
  void  **tab;

  if (!t)
    return ;
  i = 0;
  tab = (void **)t;
  size = ft_dtablen(tab);
  while (i < size)
  {
    free(tab[i]);
    i++;
  }
  free(tab);
}
