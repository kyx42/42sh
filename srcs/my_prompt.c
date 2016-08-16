/*
** my_prompt.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Jun  2 21:18:31 2016 vincent mesquita
** Last update Sun Jun  5 16:37:56 2016 Timothée Puentes
*/

#include "minishell.h"

int	my_prompt(void)
{
  char	*path;
  int	size;

  size = 0;
  path = NULL;
  if (isatty(STDIN_FILENO))
    my_printf("%s> ", (path = getcwd(NULL, 0)));
  if (path != NULL)
    {
      size = my_strlen(path);
      free(path);
    }
  return (size);
}
