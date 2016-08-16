/*
** init.c for init functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu Mar 24 16:40:37 2016 Bertrand Vautrin
** Last update Sun Jun  5 13:35:59 2016 Florian Vincent
*/

#include "minishell.h"

void	init_builtins_fct(t_builtfc *tab)
{
  tab[0] = &built_env;
  tab[1] = &built_setenv;
  tab[2] = &built_unsetenv;
  tab[3] = &built_cd;
  tab[4] = &built_cd;
  tab[5] = &built_exit;
  tab[6] = &built_echo;
  tab[7] = &built_export;
  tab[8] = &built_alias;
  tab[NB_BUILT] = NULL;
}

void	init_builtins(char **tab)
{
  tab[0] = ENV;
  tab[1] = SETENV;
  tab[2] = UNSETENV;
  tab[3] = CD;
  tab[4] = DOTDOT;
  tab[5] = EXIT;
  tab[6] = XECHO;
  tab[7] = EXPORT;
  tab[8] = ALIAS;
  tab[NB_BUILT] = NULL;
}

char	**init_path(char **env)
{
  char	**path;
  char	*tmp;
  int	i;

  if (!(tmp = my_getenv(PATH, env)))
    tmp = my_strdup(DEFAULT_PATH);
  if (!(path = my_str_to_wordtab(tmp, VAR_SEPARATOR, 1)))
    return (NULL);
  if (tmp)
    free(tmp);
  i = 0;
  while (path[i])
    {
      tmp = path[i];
      if ((path[i++] = my_strcat(tmp, "/")) == NULL)
	return (NULL);
      free(tmp);
    }
  return (path);
}
