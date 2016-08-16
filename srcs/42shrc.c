/*
** 42shrc.c for $ in /home/puente_t/rendu/PSU/PSU_2015_42sh
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon May 30 15:47:33 2016 Timothée Puentes
** Last update Sun Jun  5 16:20:14 2016 Timothée Puentes
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minishell.h"

int	read_rc(int fd, t_env *env)
{
  char	*entry;
  int	ret;

  ret = 0;
  while (ret != EXIT_VALUE &&
	 env->exit_call == 0 && (entry = get_next_line(fd)) != NULL)
    {
      if (entry != NULL && entry[0] != '#')
	ret = my_tree_exect_command(entry, env);
      free(entry);
    }
  return (ret == -1);
}

int	load_42shrc(t_env *env)
{
  char	*rc_path;
  int	fd;

  if ((rc_path = my_getenv(HOME, env->tabi)) == NULL ||
      (rc_path = my_strcat(rc_path, RC)) == NULL)
    return (1);
  if ((fd = open(rc_path, CHECK, PERM)) == -1 &&
      (fd = open(rc_path, O_RDONLY)) != -1 &&
      read_rc(fd, env) == 1)
    return (my_puterr(OPEN_ERROR));
  else if ((fd = open(rc_path, CREAT, PERM)) == -1)
    return (my_puterr(OPEN_ERROR));
  free(rc_path);
  close(fd);
  return (0);
}
