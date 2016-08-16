/*
** my_show_wordtab.c for my_show_wodtab in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Jan  8 12:26:55 2016 vincent mesquita
** Last update Sun Jun  5 14:41:17 2016 Florian Vincent
*/

#include "minishell.h"

int		my_show_wordtab(const char **wordtab)
{
  unsigned int	i;

  i = 0;
  if (wordtab == NULL)
    return (-1);
  while (wordtab[i] != NULL)
    {
      my_printf("%s\n", wordtab[i]);
      i = i + 1;
    }
  return (0);
}
