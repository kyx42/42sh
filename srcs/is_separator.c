/*
** is_separator.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 15:13:08 2016 Bertrand Vautrin
** Last update Sun Jun  5 15:29:58 2016 Florian Vincent
*/

#include "minishell.h"

int		is_separator_in(const char *str, char **sep)
{
  int		i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (sep[i])
    {
      if (my_strstr(str, sep[i]) >= 0)
	return (i);
      ++i;
    }
  return (-1);
}

int		is_separator2(const char *str, char **sep)
{
  int		i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (sep[i])
    {
      if (my_strcmp(str, sep[i]) == 0)
	return (i);
      ++i;
    }
  return (-1);
}
