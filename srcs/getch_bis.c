/*
** getch_bis.c for  in /home/puente_t/rendu/PSU/PSU_2015_42sh/ncurses
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Fri Jun  3 17:16:19 2016 Timothée Puentes
** Last update Tue Aug 16 16:13:58 2016 Florian Vincent
*/

#include <unistd.h>
#include "minishell.h"

char		*my_strcat_input(char c, char *str)
{
  int		i;
  char		*new;

  i = my_strlen(str) + 2;
  if ((new = my_malloc(i * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (str != NULL && str[i] != 0)
    {
      new[i] = str[i];
      i += 1;
    }
  new[i++] = c;
  new[i] = 0;
  return (new);
}

int		my_istrcmp(const char *cmp, const char *new)
{
  int		c;

  c = 0;
  while (cmp[c] != 0 && new[c] != 0)
    {
      if (cmp[c] != new[c])
	return (-1);
      c += 1;
    }
  if (cmp[c] == 0)
    return (0);
  if (cmp[c] != 0 && new[c] == 0)
    return (1);
  return (-1);
}

void		init_ptr(t_env *env)
{
  env->term = my_getenv("TERM", env->tabi);
  env->fptr[0] = &my_back;
  env->fptr[1] = &my_forward;
  env->fptr[2] = &my_up;
  env->fptr[3] = &my_down;
  env->fptr[4] = &my_tab;
  env->fptr[5] = &my_del;
}
