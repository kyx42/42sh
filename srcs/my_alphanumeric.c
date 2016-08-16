/*
** my_alphanumeric.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon May 30 12:49:06 2016 vincent mesquita
** Last update Sun Jun  5 15:43:30 2016 Florian Vincent
*/

#include "minishell.h"

int		my_alphanumeric(const char *str)
{
  unsigned int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9')
	  && !(str[i] >= 'a' && str[i] <= 'z')
	  && !(str[i] >= 'A' && str[i] <= 'Z'))
	return (0);
      i += 1;
    }
  return (1);
}
