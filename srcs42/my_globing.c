/*
** my_globing.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon May 30 14:38:02 2016 vincent mesquita
** Last update Wed Jun  1 17:40:02 2016 vincent mesquita
*/

#include <glob.h>
#include "minishell.h"

# define NO_MATCH	"No match.\n"

static char	**my_init_cpy(const char *str)
{
  char		**cpy;

  if (!(cpy = malloc(2 * sizeof(char *)))
      || !(cpy[0] = my_strdup(str)))
    return (NULL);
  cpy[1] = NULL;
  return (cpy);
}

static char	**my_glob(const char *pattern,
			  const char *command)
{
  glob_t	glob_buffer;
  unsigned int		ret;
  const char	*glob_err[3] =
    {
      MALLOC_ERR,
      READ_ERR,
      NO_MATCH
    };
  ret = glob(pattern, 0, NULL, &glob_buffer);
  if (ret != 0 && ret != 3)
    {
      my_puterr(command);
      my_puterr(": ");
      my_puterr(glob_err[ret - 1]);
      return (NULL);
    }
  if (glob_buffer.gl_pathv == NULL
      && !(glob_buffer.gl_pathv = my_init_cpy(pattern)))
    return (NULL);
  return (glob_buffer.gl_pathv);
}

char		**my_globing(char **av)
{
  unsigned int	i;
  char		**cpy;

  i = 1;
  if (!av || !(cpy = my_init_cpy(av[0])))
    return (NULL);
  while (av[i])
    {
      if (!(cpy = my_wordtab_cat(cpy, my_glob(av[i], av[0]), 1)))
	return (av);
      i += 1;
    }
  if (av)
    free_tab(av);
  return (cpy);
}
