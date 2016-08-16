/*
** basic2.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 14:39:12 2016 Bertrand Vautrin
** Last update Sun Jun  5 15:33:01 2016 Florian Vincent
*/

#include "minishell.h"

int	my_strstr(const char *str, const char *find)
{
  int	i;
  int	j;

  i = 0;
  while (str[i])
    {
      j = 0;
      while (str[i] != find[j] && str[i] != 0)
	++i;
      while (str[i] == find[j] && find[j] != 0)
	{
	  ++i;
	  ++j;
	}
      if (find[j] == 0)
	return (i);
    }
  return (-1);
}

int	my_puterr(const char *str)
{
  (void)write(2, str, my_strlen(str));
  return (-1);
}

void	my_putchar(char c)
{
  (void)(write(1, &c, 1));
}

void	my_putnbr_base(int nbr, char *base)
{
  int	base_length;

  base_length = my_strlen(base);
  if (nbr >= base_length)
    my_putnbr_base(nbr / base_length, base);
  my_putchar(base[nbr % base_length]);
}
