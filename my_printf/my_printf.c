/*
** my_printf.c for my_printf in /home/vautri_b/Projets/Projets_S1/Printf/My_Printf
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed Nov  4 14:41:10 2015 Bertrand Vautrin
** Last update Fri Dec 11 01:57:00 2015 Bertrand Vautrin
*/

#include "my_printf.h"

int		check_space(int i, const char *format)
{
  while (format[i] == ' ')
    i = i + 1;
  return (i);
}

int		my_printf_2(char format, va_list ap, t_fct *tab, int *ccp)
{
  int	count;

  count = 0;
  while (count != NB_OF_FLAGS)
    {
      if (format == tab[count].flag)
	{
	  tab[count].fct(ap, ccp);
	  return (0);
	}
      count = count + 1;
    }
  my_putchar_spe('%', ccp);
  return (1);
}

int		my_printf(const char *format, ...)
{
  t_fct		tab[NB_OF_FLAGS];
  va_list	ap;
  int		i;
  int		count_char_print;

  if (format == NULL)
    return (-1);
  count_char_print = 0;
  _init_tab(tab);
  va_start(ap, format);
  i = 0;
    while (format[i] != '\0')
    {
      if (format[i++] == '%')
	{
	  i = check_space(i, format);
	  if (format[i] == 0)
	     return (-1);
	  if (my_printf_2(format[i++], ap, tab, &count_char_print) == 1)
	    my_putchar_spe(format[i - 1], &count_char_print);
	}
      else
	my_putchar_spe(format[i - 1], &count_char_print);
    }
  return (count_char_print);
}
