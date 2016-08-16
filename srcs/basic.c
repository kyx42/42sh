/*
** len.c for len functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed Mar 23 10:26:11 2016 Bertrand Vautrin
** Last update Sun Jun  5 14:14:06 2016 Florian Vincent
*/

#include <stdlib.h>
#include "minishell.h"

int	my_strtablen(char **tab)
{
  int	i;

  if (tab == NULL)
    return (0);
  i = 0;
  while (tab[i])
    i = i + 1;
  return (i);
}

int	my_strlen(const char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

char	*my_strdup(const char *str)
{
  char	*dup;
  int	i;

  if (str == NULL ||
      (dup = my_malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      dup[i] = str[i];
      i++;
    }
  dup[i] = 0;
  return (dup);
}

char	**my_strtabdup(char **tab)
{
  char	**dup;
  int	i;

  if (tab == NULL ||
      (dup = my_malloc((my_strtablen(tab) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (tab[i])
    {
      if (!(dup[i] = my_strdup(tab[i])))
	return (NULL);
      i++;
    }
  dup[i] = NULL;
  return (dup);
}

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  if (s1 == NULL && s2 == NULL)
    return (0);
  if (s1 == NULL || s2 == NULL)
    return (-1);
  i = 0;
  while (s1[i] != 0)
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  if (s2[i] == 0)
    return (0);
  return (i);
}
