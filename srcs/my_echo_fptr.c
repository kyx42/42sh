/*
** my_echo_fptr.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed May 25 16:05:04 2016 vincent mesquita
** Last update Sun Jun  5 15:52:04 2016 Florian Vincent
*/

#include "minishell.h"
#include "echo.h"

static void	my_init_struct(t_backslash_escape *be,
				       char *flag,
				       fptr *fptr)
{
  be->flag = flag;
  be->fptr = fptr;
}

void		my_init_backslash_escape_tab(t_backslash_escape
					     tab[ESCAPE_NBR])
{
  my_init_struct(&tab[0], "\\\\", my_backslash);
  my_init_struct(&tab[1], "\\a", my_backslash_a);
  my_init_struct(&tab[2], "\\b", my_backslash_b);
  my_init_struct(&tab[3], "\\c", my_backslash_c);
  my_init_struct(&tab[4], "\\e", my_backslash_e);
  my_init_struct(&tab[5], "\\f", my_backslash_f);
  my_init_struct(&tab[6], "\\n", my_backslash_n);
  my_init_struct(&tab[7], "\\r", my_backslash_r);
  my_init_struct(&tab[8], "\\t", my_backslash_t);
  my_init_struct(&tab[9], "\\v", my_backslash_v);
  my_init_struct(&tab[10], "\\0", my_backslash_bi);
  my_init_struct(&tab[11], "\\x", my_backslash_hex);
}

void		my_print_backslash_esc(char *escape,
				       t_backslash_escape tab[ESCAPE_NBR],
				       char *str,
				       unsigned int *index)
{
  unsigned int	i;

  i = 0;
  while (i < ESCAPE_NBR)
    {
      if (my_strcmp(escape, tab[i].flag) == 0)
	{
	  tab[i].fptr(str, index);
	  break ;
	}
      i += 1;
    }
  if (i == ESCAPE_NBR)
    {
      my_printf(&escape[1]);
      *index += 1;
    }
}
