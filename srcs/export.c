/*
** export.c for  in /home/puente_t/rendu/PSU/PSU_2015_42sh
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon May 30 14:00:30 2016 Timothée Puentes
** Last update Sun Jun  5 16:19:56 2016 Timothée Puentes
*/

#include "minishell.h"

static int		check_export(const char *str)
{
  int			c;

  c = 0;
  while (str[c] != 0)
    if (str[c++] == '=')
      return (c);
  return (-1);
}

static char		*my_strncat(const char *str, int n)
{
  char			*new;
  int			size;
  int			c;

  size = ((n < my_strlen(str)) ? (n) : (my_strlen(str)));
  if ((new = my_malloc(size + 1)) == NULL)
    return (NULL);
  c = 0;
  while (c < size)
    {
      new[c] = str[c];
      c += 1;
    }
  new[c] = 0;
  return (new);
}

int			built_export(char **av, t_env *env)
{
  char			*str;
  int			c;

  if (av[1] == NULL)
    my_putstrtab(env->tabi);
  else if ((c = check_export(av[1])) == -1)
    my_unsetenv(av[1], env);
  else
    {
      if (c - 1 <= 0)
	return (my_puterr(EXPORT_INVALID));
      if ((str = my_strncat(av[1], c - 1)) == NULL)
	return (1);
      printf("%s %s\n", str, &av[1][c]);
      my_setenv(str, &av[1][c], env);
      free(str);
    }
  return (0);
}
