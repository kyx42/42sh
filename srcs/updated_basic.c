/*
** updated_basic.c for updated basic functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu Mar 24 16:23:14 2016 Bertrand Vautrin
** Last update Sun Jun  5 14:50:09 2016 Timothée Puentes
*/

#include "minishell.h"

int	my_nstrlen(const char *str, int beg)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[beg++])
    i = i + 1;
  return (i);
}

char	*my_nstrdup(const char *str, int beg)
{
  char	*dup;
  int	i;

  if (str == NULL ||
      (dup = my_malloc((my_nstrlen(str, beg) + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (str[beg])
    {
      dup[i] = str[beg++];
      i++;
    }
  dup[i] = 0;
  return (dup);
}

char	*my_strcat(const char *s1, const char *s2)
{
  int	i;
  int	j;
  char	*str;

  i = my_strlen(s1) + my_strlen(s2) + 1;
  if ((str = my_malloc(i * sizeof(char))) == NULL)
    return (NULL);
  i = -1;
  while (s1 && s1[++i])
    str[i] = s1[i];
  j = 0;
  while (s2 && s2[j])
    str[i++] = s2[j++];
  if (i > -1)
    str[i] = 0;
  else
    str[0] = 0;
  return (str);
}

int	my_get_nbr(const char *str)
{
  int	i;
  int	j;
  int	nbr;

  if (str == NULL)
    return (0);
  i = 0;
  j = 0;
  nbr = 0;
  while (str[i] == '-')
    {
      j = j + 1;
      i = i + 1;
    }
  while (str[i] <= '9' && str[i] >= '0')
    {
      if (nbr == 214748364 && str[i] == '8')
	return (-2147483648);
      nbr = str[i] - '0' + nbr * 10;
      i = i + 1;
    }
  if (j % 2 != 0)
    nbr = -nbr;
  return (nbr);
}

int	my_get_n_nbr(const char *str, int n)
{
  int	i;
  int	nbr;
  int	neg;

  i = 0;
  nbr = 0;
  neg = 0;
  if (str == NULL)
    return (-1);
  while ((str[i] < '0' || str[i] > '9') && str[i] != 0 && i < n)
    {
      if (str[i] == '-')
	neg = neg + 1;
      i = i + 1;
    }
  while (str[i] >= '0' && str[i] <= '9' && i < n)
    {
      nbr = nbr * 10 + str[i] - 48;
      i = i + 1;
    }
  if (neg % 2 == 1)
    nbr = nbr * (-1);
  return (nbr);
}
