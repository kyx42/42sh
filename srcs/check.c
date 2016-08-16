/*
** check.c for check functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu Mar 24 16:27:48 2016 Bertrand Vautrin
** Last update Sun Jun  5 15:51:44 2016 Florian Vincent
*/

#include "minishell.h"

static int	is_a_directory(const char *filename)
{
  int		fd;

  if ((fd = open(filename, O_DIRECTORY))< 0)
    return (0);
  (void)(close(fd));
  my_puterr(filename);
  my_puterr(": Permission denied.\n");
  return (1);
}

int		check_access(const char *filename)
{
  if (access(filename, F_OK) == 0)
    {
      if (access(filename, X_OK) == 0)
	return (0);
      else
	return (-2);
    }
  return (-1);
}

int	check_command(char **av, char **path, char **tmp)
{
  int	ret;

  ret = 0;
  if (is_builtins(av[0]) == 0)
    ret = 2;
  else if (is_path(av[0]) == 0)
    {
      if (is_a_directory(av[0]))
	return (1);
      ret = check_access(av[0]);
    }
  else if (path == NULL || (*tmp = find_path_command(av, path)) == NULL)
    ret = -1;
  if (ret < 0)
    {
      my_puterr(av[0]);
      my_puterr(COMMAND_NOT_FOUND);
      ret = 1;
    }
  return (ret);
}
