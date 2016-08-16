/*
** my_wordtab_cat.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon May 30 15:54:19 2016 vincent mesquita
** Last update Sun Jun  5 14:43:39 2016 Florian Vincent
*/

#include "minishell.h"

char		**my_wordtab_cat(char **w1,
				 char **w2,
				 int free_flag)
{
  char		**cpy;
  unsigned int	i;
  unsigned int	j;

  if (!w2
      || !(cpy = malloc((my_strtablen(w1) + my_strtablen(w2) + 1)
			* sizeof(char *))))
    return (NULL);
  i = 0;
  j = 0;
  while (w1 && w1[j])
    if (!(cpy[i++] = my_strdup(w1[j++])))
      return (NULL);
  j = 0;
  while (w2[j])
    if (!(cpy[i++] = my_strdup(w2[j++])))
      return (NULL);
  cpy[i] = NULL;
  if (w2 && free_flag == 1)
    free_tab(w2);
  return (cpy);
}
