/*
** ncurses.c for  in /home/puente_t/rendu/PSU/PSU_2015_42sh/ncurses
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon May 30 16:14:37 2016 Timothée Puentes
** Last update Sun Jun  5 16:53:14 2016 Timothée Puentes
*/

#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include "minishell.h"

void			set_termios_bis(t_env *env)
{
  char			*str;

  env->input[0] = tigetstr("kcub1");
  env->input[1] = tigetstr("kcuf1");
  env->input[2] = tigetstr("kcuu1");
  env->input[3] = tigetstr("kcud1");
  env->input[4] = my_strdup("\t");
  env->input[5] = my_strdup("\b");
  env->input[5][0] = 127;
  if ((str = tigetstr("smkx")) == (void*)-1 || str == NULL)
    {
      set_termios(1, env);
      exit(1);
    }
  puts(str);
  env->up = tigetstr("cuu1");
  env->right = tigetstr("cuf1");
  env->left = tigetstr("cub1");
  env->stop = tigetstr("rmkx");
  env->width = tigetnum("cols");
}

int			set_termios(int i, t_env *env)
{
  static struct termios	old;
  static struct termios	new;
  int			err;

  if (i == 0)
    {
      init_ptr(env);
      ioctl(0, TCGETS, &old);
      ioctl(0, TCGETS, &new);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      new.c_cc[VMIN] = 1;
      new.c_cc[VTIME] = 0;
      ioctl(0, TCSETS, &new);
      setupterm(env->term, 0, &err);
      if (err == ERR)
	exit(-my_puterr(MALLOC_ERR));
      set_termios_bis(env);
    }
  else
    ioctl(0, TCSETS, &old);
  return (0);
}
