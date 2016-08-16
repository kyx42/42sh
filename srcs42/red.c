/*
** red.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 14:49:30 2016 Bertrand Vautrin
** Last update Wed May 25 16:20:25 2016 Bertrand Vautrin
*/

#include "minishell.h"

int		find_red_line(char *str, char *sep)
{
  int		i;
  int		len;

  if ((i = my_strstr(str, sep)) < 0)
    return (-1);
  while (str[i] != ' ' && str[i] != '\t' && str[i] != 0)
    ++i;
  len = 0;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  while (str[i] != ' ' && str[i] != '\t' && str[i] > 0)
    {
      ++len;
      ++i;
    }
  return (len);
}

char		*recup_red(char *str, char *sep)
{
  int		i;
  int		j;
  char		*red;

  i = find_red_line(str, sep) + 1;
  if (i < 0 || (red = my_malloc(i * sizeof(char))) == NULL)
    return (NULL);
  i = my_strstr(str, sep);
  j = -1;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  while (str[i] != ' ' && str[i] != '\t' && str[i] > 0)
    red[++j] = str[i++];
  red[++j] = 0;
  return (red);
}

char		*without_red(char *str, char *red)
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

char		*red_cut(char *str, char *sep, char *red)
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
