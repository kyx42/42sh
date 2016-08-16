/*
** find.c for find functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu Mar 24 16:43:21 2016 Bertrand Vautrin
** Last update Sun Jun  5 13:45:49 2016 Florian Vincent
*/

#include "minishell.h"

char	*find_path_command(char **av, char **path)
{
  int	i;
  char	*tmp;

  i = 0;
  while (path[i])
    {
      tmp = my_strcat(path[i++], av[0]);
      if (check_access(tmp) == 0)
	return (tmp);
      free(tmp);
    }
  return (NULL);
}
