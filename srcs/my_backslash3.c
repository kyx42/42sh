/*
** my_backslah3.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed May 25 16:26:14 2016 vincent mesquita
** Last update Sun Jun  5 14:41:37 2016 Florian Vincent
*/

#include "minishell.h"
#include "echo.h"

static int	my_pow(const int nbr, const int pow)
{
  int		i;
  int		result;

  i = 0;
  result = 1;
  while (i < pow)
    {
      result *= nbr;
      i += 1;
    }
  return (result);
}

static int	my_convert(int nbr, const int base)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (nbr > 0)
    {
      nb = nb + (nbr % 10) * my_pow(base, i);
      nbr /= 10;
      i += 1;
    }
  return (nb);
}

static void	my_increment_index(unsigned int *i, int nbr)
{
  int		y;

  y = 0;
  while (nbr > 0)
    {
      y += 1;
      nbr /= 10;
    }
  if (y != 0)
    *i += 4;
}

void		my_backslash_bi(char *str, unsigned int *i)
{
  int		nbr;

  nbr = my_get_n_nbr(str, OCT_LENGTH);
  my_printf("NBR = %d\n", nbr);
  my_putchar(my_convert(nbr, OCT));
  my_increment_index(i, nbr);
}

void		my_backslash_hex(char *str, unsigned int *i)
{
  int		nbr;

  nbr = my_get_n_nbr(str, HEX_LENGTH);
  my_putchar(my_convert(nbr, HEX));
  my_increment_index(i, nbr);
}
