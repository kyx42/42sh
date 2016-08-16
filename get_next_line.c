/*
** get_next_line.c for  in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Apr  8 01:33:42 2016 vincent mesquita
** Last update Fri Apr  8 01:33:53 2016 vincent mesquita
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*my_strcat_gnl(char *str1, char *str2)
{
  char		*cpy;
  int		i;
  int		h;

  i = 0;
  h = 0;
  while (str1 != NULL && str1[i])
    i = i + 1;
  while (str2[h])
    h = h + 1;
  if ((cpy = malloc((i + h + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (str1 != NULL && str1[i])
    {
      cpy[i] = str1[i];
      i = i + 1;
    }
  h = 0;
  while (str2[h] && str2[h])
    cpy[i++] = str2[h++];
  if (str1 != NULL)
    free(str1);
  cpy[i] = '\0';
  return (cpy);
}

char		*get_the_current_line(char *str, int length,
				      char *current_line)
{
  static int	i = 0;
  int		i_save;

  if (str == NULL || str[i] == 0)
    {
      if (str != NULL)
	free(str);
      return (NULL);
    }
  length = 0;
  i_save = i;
  while (str[i] && str[i] != '\n')
    {
      length = length + 1;
      i = i + 1;
    }
  if (str[i] != 0)
    i = i + 1;
  if ((current_line = malloc((length + 1) * sizeof(char))) == NULL)
    return (NULL);
  length = 0;
  while (str[i_save] && str[i_save] != '\n')
    current_line[length++] = str[i_save++];
  current_line[length] = 0;
  return (current_line);
}

int		my_check_back_slash_n(char *str, int flag)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  if (flag == 0)
    {
      while (str[i])
	{
	  if (str[i] == '\n')
	    return (1);
	  i = i + 1;
	}
    }
  else
    {
      while (str[i])
	{
	  if (str[i] == '\n')
	    str[i] = 0;
	  i = i + 1;
	}
    }
  return (0);
}

char		*get_next_line2(const int fd)
{
  char		*buffer;
  char		*current_line;
  int		end;

  current_line = NULL;
  if ((buffer = malloc((READ_SIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (1)
    {
      if ((end = read(fd, buffer, READ_SIZE)) < 1)
	{
	  free(buffer);
	  return (NULL);
	}
      buffer[end] = 0;
      current_line = my_strcat_gnl(current_line, buffer);
      if (my_check_back_slash_n(buffer, 0) == 1)
	{
	  free(buffer);
	  my_check_back_slash_n(current_line, 1);
	  return (current_line);
	}
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	*lines = NULL;
  char		*buffer;
  char		*current_line;
  int		end;

  if (fd <= 2)
    return (get_next_line2(fd));
  if ((buffer = malloc((READ_SIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  while ((end = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[end] = 0;
      lines = my_strcat_gnl(lines, buffer);
    }
  free(buffer);
  current_line = get_the_current_line(lines, 0, NULL);
  return (current_line);
}
