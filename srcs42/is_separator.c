/*
** is_separator.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 15:13:08 2016 Bertrand Vautrin
** Last update Tue May  3 15:17:29 2016 Bertrand Vautrin
*/

#include "minishell.h"

int		is_separator_in(char *str, char **sep)
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

int		is_separator2(char *str, char **sep)
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
