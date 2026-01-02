#include  "../inc/libft.h"

size_t	ft_dtablen(void *s)
{
  size_t	i;
  void  **tab;

  i = 0;
  if (!s)
    return (0);
  tab = (void **)s;
  while (tab[i])
    i++;
  return (i);
}
