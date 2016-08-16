/*
** getch.c for  in /home/puente_t/rendu/PSU/PSU_2015_42sh/ncurses
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Fri Jun  3 17:14:48 2016 Timothée Puentes
** Last update Tue Aug 16 15:56:43 2016 Florian Vincent
*/

#include <curses.h>
#include "minishell.h"

char		*free_char(char *str, int ret)
{
  if (ret > 0)
    return (str);
  free(str);
  return (NULL);
}

void		print_normal(char *input, int *idx)
{
  int		i;

  my_printf(&input[*idx - 1]);
  i = -1;
  while (++i + *idx < my_strlen(input))
    my_putchar('\b');
}

char		*getchbis(t_env *env, int *idx, char *input, int c)
{
  static char	*act = NULL;
  char		*tmp;
  int		ret;
  int		i;

  tmp = my_strcat_input(c, act);
  free(act);
  ret = -1;
  act = tmp;
  i = 0;
  while (i < NB_CAPABILITY &&
	 (ret = my_istrcmp(env->input[i], act)) == -1)
    i += 1;
  if (ret == -1)
    {
      tmp = my_add_char(input, act[0], *idx);
      *idx += 1;
      free(input);
      input = tmp;
      print_normal(input, idx);
    }
  else if ((ret == 0 && i < NB_CAPABILITY))
    input = env->fptr[i](idx, input, env);
  act = free_char(act, ret);
  return (input);
}

char		*getch_next(t_env *env)
{
  char		*input;
  char		c;
  int		readed;
  int		idx;

  c = 0;
  input = my_strdup("");
  idx = 0;
  env->curr = env->histo;
  while ((readed = read(0, &c, 1)) > 0 && c != '\n' && c != 4)
    input = getchbis(env, &idx, input, c);
  my_putchar('\n');
  if (readed == -1)
    exit(my_puterr(MALLOC_ERR));
  return (((c != 4) ? (input) : (NULL)));
}
