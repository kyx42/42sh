/*
** red.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 14:49:30 2016 Bertrand Vautrin
** Last update Sun Jun  5 15:27:09 2016 Florian Vincent
*/

#include "minishell.h"

static int		find_red_line(const char *str, const char *sep)
{
  int		i;
  int		len;

  if ((i = my_strstr(str, sep)) < 0)
    return (-1);
  while (str[i] != SPACE && str[i] != TAB && str[i] != 0)
    ++i;
  len = 0;
  while (str[i] == SPACE || str[i] == TAB)
    ++i;
  while (str[i] != SPACE && str[i] != TAB && str[i] > 0)
    {
      ++len;
      ++i;
    }
  return (len);
}

static char		*recup_red(const char *str, const char *sep)
{
  int		i;
  int		j;
  char		*red;

  i = find_red_line(str, sep) + 1;
  if (i < 0 || (red = my_malloc(i * sizeof(char))) == NULL)
    return (NULL);
  i = my_strstr(str, sep);
  j = -1;
  while (str[i] == SPACE || str[i] == TAB)
    ++i;
  while (str[i] != SPACE && str[i] != TAB && str[i] > 0)
    red[++j] = str[i++];
  red[++j] = 0;
  return (red);
}

static char		*without_red(const char *str, const char *red)
{
  int		i;
  int		j;
  int		ret;
  char		*new;

  i = my_strlen(str) - my_strlen(red) + 1;
  if ((new = my_malloc(i * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  ret = my_strstr(str, red) - my_strlen(red);
  while (i != ret)
    new[j++] = str[i++];
  i = ret + my_strlen(red);
  while (str[i])
    new[j++] = str[i++];
  new[j] = 0;
  return (new);
}

char		*red_cut(const char *str, const char *sep, const char *red)
{
  char		*tmp;
  char		*new;

  if (red == NULL)
    new = recup_red(str, sep);
  else
    {
      tmp = without_red(str, red);
      new = without_red(tmp, sep);
      free(tmp);
    }
  return (new);
}
