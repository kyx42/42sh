/*
** auto_completion.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh/srcs42/auto_completion
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu May 26 17:55:02 2016 vincent mesquita
** Last update Tue Aug 16 16:18:46 2016 Florian Vincent
*/

#include <glob.h>
#include <stdio.h>
#include <stdlib.h>

int		globi(char *str)
{
  glob_t	glob_buffer;
  unsigned int		ret;

  ret = glob(str, 0, NULL, &glob_buffer);
  while (ret < glob_buffer.gl_pathc)
    printf("%s\n", glob_buffer.gl_pathv[ret++]);
  return (0);
}
