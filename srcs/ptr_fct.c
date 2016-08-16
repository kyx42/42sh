/*
** ptr_fct.c for ptr_fct.c in /home/vincen_s/rendu/PSU_2015_42sh/ncurses/srcs
**
** Made by Florian Vincent
** Login   <vincen_s@epitech.net>
**
** Started on  Tue May 31 12:24:57 2016 Florian Vincent
** Last update Tue Aug 16 15:56:00 2016 Florian Vincent
*/

#include <term.h>
#include "minishell.h"

char		*my_down(int *idx, char *line, t_env *env)
{
  (void)env;
  if (env->curr->suiv == env->histo)
    return (line);
  change_word(env, line, idx);
  if (line)
    free(line);
  env->curr = env->curr->suiv;
  line = my_strdup(env->curr->entry);
  *idx = my_strlen(line);
  my_printf(line);
  return (line);
}

char		*my_tab(int *idx, char *line, t_env *env)
{
  (void)env;
  (void)*idx;
  globi(line);
  return (line);
}

char		*my_strdeldup(char *str, int idx)
{
  char		*new;
  int		i;
  int		size;

  idx -= 1;
  if ((size = my_strlen(str)) <= 0)
    return (NULL);
  new = my_malloc(size + 1);
  i = 0;
  while (i < idx && i < size)
    {
      new[i] = str[i];
      i += 1;
    }
  while (i < size)
    {
      new[i] = str[i + 1];
      i += 1;
    }
  new[i] = 0;
  return (new);
}

char		*my_del(int *idx, char *line, t_env *env)
{
  char		*tmp;
  int		i;

  if ((tmp = my_strdeldup(line, *idx)) == NULL || *idx <= 0)
    return (line);
  change_word(env, line, idx);
  my_printf(tmp);
  i = -1;
  while (my_strlen(line) > 0 && ++i < my_strlen(line) - *idx)
    my_printf("\b");
  *idx -= 1;
  free(line);
  line = tmp;
  (void)env;
  return (line);
}
