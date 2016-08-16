/*
** cut_string.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 14:40:48 2016 Bertrand Vautrin
** Last update Tue May  3 14:47:58 2016 Bertrand Vautrin
*/

#include "minishell.h"

int	find_len(char *str, char *sep, int flag)
{
  int	i;
  int	j;

  i = 0;
  while (str[i])
    {
      j = 0;
      while (str[i] != sep[j] && str[i] != 0)
	++i;
      while (str[i] == sep[j] && sep[j] != 0)
	{
	  ++i;
	  ++j;
	}
      if (sep[j] == 0)
	{
	  if (flag == 0)
	    return (i - my_strlen(sep));
	  if (flag == 1)
	    return (my_strlen(str) - i);
	}
    }
  return (0);
}

char	*cut(char *str, char *separator, int flag)
{
  int	len;
  int	i;
  int	j;
  char	*new;

  len = find_len(str, separator, flag);
  if ((new = my_malloc((len + 1) * sizeof(char))) == NULL)
    return (NULL);
  j = 0;
  if (flag == 1)
    j = find_len(str, separator, 0) + my_strlen(separator);
  i = 0;
  while (i < len)
    new[i++] = str[j++];
  new[i] = 0;
  return (new);
}
