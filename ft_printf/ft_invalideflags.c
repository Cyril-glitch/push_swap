#include "libft.h"
#include "ft_printf.h"

int ft_invalideflags(char end, t_flags *f)
{
  int count;
  char *nombre;

  count = 0;
	if (!ft_isset(end, "cspdiuxX") || end == '.')
  {
		  count = write(1, "%", 1);
      count += write(1, &end, 1);
    if (f->hash)
      count += write(1, "#", 1);
    if (f->plus)
      count += write(1, "+", 1);
    if (f->minus)
      count += write(1, "-", 1);
    if (f->width)
    {
      nombre = ft_itoa(f->width); 
      count += write(1, nombre, ft_strlen(nombre));
    }
    if (end == '.')
      count += write(1, ".0", 1);
  }
  return (count);
}
