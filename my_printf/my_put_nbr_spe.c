/*
** my_put_nbr_spe.c for my_put_nbr_spe in /home/vautri_b/Projets/Projets_S1/Printf/My_Printf/srcs
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu Nov  5 12:02:12 2015 Bertrand Vautrin
** Last update Fri Apr  8 14:31:36 2016 Bertrand Vautrin
*/

#include "my_printf.h"

int		my_put_nbr_spe(int nb, int *ccp)
{
  if (nb == -2147483648)
    {
      my_putstr_spe("-2147483648", ccp);
      return (0);
    }
  if (nb < 0)
    {
      my_putchar_spe('-', ccp);
      nb = -nb;
    }
  if (nb > 9)
    {
      my_put_nbr_spe(nb / 10, ccp);
      my_put_nbr_spe(nb % 10, ccp);
    }
  else
    my_putchar_spe(nb + 48, ccp);
  return (0);
}

int		my_put_nbr_base_spe_long(long nb, char *base, int *ccp)
{
  int		length;

  length = my_strlen(base);
  if (nb >= length)
    my_put_nbr_base_spe_long(nb / length, base, ccp);
  my_putchar_spe(base[nb % length], ccp);
  return (0);
}

int		my_put_nbr_base_spe(unsigned int nb, char *base, int *ccp)
{
  unsigned int	length;

  length = my_strlen(base);
  if (nb >= length)
    my_put_nbr_base_spe(nb / length, base, ccp);
  my_putchar_spe(base[nb % length], ccp);
  return (0);
}

int		my_put_nbr_u_spe(unsigned int nb, int *ccp)
{
  if (nb == 4294967295)
    {
      my_putstr_spe("4294967295", ccp);
      return (0);
    }
  if (nb > 9)
    {
      my_put_nbr_u_spe(nb / 10, ccp);
      my_put_nbr_u_spe(nb % 10, ccp);
    }
  else
    my_putchar_spe(nb + 48, ccp);
  return (0);
}
