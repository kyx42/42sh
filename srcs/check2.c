/*
** check2.c for check functions is_ in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Fri Mar 25 16:44:45 2016 Bertrand Vautrin
** Last update Sun Jun  5 14:01:02 2016 Florian Vincent
*/

#include "minishell.h"

int	is_builtins(const char *str)
{
  char	*built[NB_BUILT + 1];
  int	i;

  init_builtins(built);
  i = 0;
  while (built[i])
    if (my_strcmp(str, built[i++]) == 0)
      return (0);
  return (-1);
}

int	is_path(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    if (str[i++] == SLASH)
      return (0);
  return (-1);
}

int	is_num(const char *str)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
	return (-1);
      if (str[i] == '-')
	++ret;
      ++i;
    }
  if (ret > 1 || (ret && str[0] != '-'))
    return (-2);
  return (0);
}
