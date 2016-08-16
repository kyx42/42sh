/*
** get_next_line.c for function my_get_line in /home/vautri_b/Projets/Projets_S1/GetNextLine/Projet
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Mon Jan  4 13:26:42 2016 Bertrand Vautrin
** Last update Wed Mar 23 15:00:39 2016 Bertrand Vautrin
*/

#include "get_next_line.h"

char	*my_strcat2(char *dest, const char *src)
{
  char	*str;
  int	len;
  int	i;
  int	j;

  len = 0;
  i = 0;
  while (dest[i++])
    len = len + 1;
  i = 0;
  while (src[i++])
    len = len + 1;
  if ((str = my_malloc((len + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (dest[i++])
    str[i - 1] = dest[i - 1];
  i = i - 1;
  j = 0;
  while (src[j])
    str[i++] = src[j++];
  str[i] = '\0';
  free(dest);
  dest = str;
  return (dest);
}

char		*initstring(void)
{
  char		*str;

  str = my_malloc(sizeof(char));
  if (str == NULL)
    return (NULL);
  str[0] = '\0';
  return (str);
}

int		is_line(char *str, int pos)
{
  int	i;

  i = pos;
  while (str[i])
    if (str[i++] == '\n')
      return (YES);
  return (NO);
}

char		*set_line(char *save, int *i)
{
  int		j;
  int		k;
  char		*line;

  if (save == NULL || save[*i] == 0)
    return (NULL);
  j = *i;
  while (save[j] != '\n' && save[j] != 0)
    j = j + 1;
  if ((line = my_malloc((j + 1) * sizeof(char))) == NULL)
    return (NULL);
  k = 0;
  while (save[*i] != '\n' && save[*i] != 0)
    {
      line[k++] = save[*i];
      *i = *i + 1;
    }
  line[k] = 0;
  if (save[*i] == '\n')
    *i = *i + 1;
  return (line);
}

char		*get_next_line(const int fd)
{
  static char	*save;
  static int	i;
  t_vars	var;

  if (save == NULL && (save = initstring()) == NULL)
    return (NULL);
  if ((var.ror = read(fd, var.buff, READ_SIZE)) <= 0)
    {
      free(save);
      return (NULL);
    }
  var.buff[var.ror] = 0;
  save = my_strcat2(save, var.buff);
  var.j = 0;
  while (var.j <= READ_SIZE)
    var.buff[var.j++] = 0;
  while (is_line(save, i) == NO && read(fd, var.buff, READ_SIZE) > 0)
    {
      var.buff[var.ror] = 0;
      save = my_strcat2(save, var.buff);
      var.j = 0;
      while (var.j <= READ_SIZE)
	var.buff[var.j++] = 0;
    }
  return (set_line(save, &i));
}
