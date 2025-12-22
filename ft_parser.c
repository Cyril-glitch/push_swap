static void ft_convert(char *av, t_dlist **new)
{
  int i;
  
  i = 0;
  while (av[i])
  {
    if (av[i] == '-' || av[i] == '+' || ft_isdigit(av[i]))
    {
      ft_lstaddfront(new, ft_lstnew(ft_atol(av[i])));
      while (av[i] == '-' || av[i] == '+' || ft_isdigit(av[i]))
        i++;
    }
    if (ft_isspace(av[i]))
      i++;
  }
}

t_dlist *ft_parser(int ac, char **av)
{

  int i;
  t_dlist *new;

  i = 0;
  while (i < ac)
  {
    ft_convert(av[i], new);
    i++;
  }
}
