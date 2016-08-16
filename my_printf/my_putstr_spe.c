/*
** my_putstr_spe.c for my_putstr_spe in /home/vautri_b/Projets/Projets_S1/Printf/My_Printf/srcs
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu Nov  5 12:00:56 2015 Bertrand Vautrin
** Last update Mon Nov 16 14:31:08 2015 Bertrand Vautrin
*/

#include "my_printf.h"

void	my_putstr_spe(char *str, int *ccp)
{
  int	i;

  if (str == NULL)
    {
      my_putstr_spe("(null)", ccp);
      return;
    }
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_spe(str[i], ccp);
      i = i + 1;
    }
}

void	my_putstr_spe_S(char *str, int *ccp)
{
  int	i;

  if (str == NULL)
    {
      my_putstr_spe("(null)", ccp);
      return;
    }
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar_spe('\\', ccp);
	  if (str[i] < 80)
	    my_putchar_spe('0', ccp);
	  if (str[i] < 8)
	    my_putchar_spe('0', ccp);
	  my_put_nbr_base_spe(str[i], "01234567", ccp);
	}
      else
	my_putchar_spe(str[i], ccp);
      i = i + 1;
    }
}
