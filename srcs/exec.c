/*
** exec.c for exec functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu Mar 24 16:32:35 2016 Bertrand Vautrin
** Last update Sun Jun  5 16:15:44 2016 Timothée Puentes
*/

#include "minishell.h"

int		my_exect(char * const av[], t_env *env, const char *name)
{
  pid_t		frv;
  int		status;

  if (name == NULL)
    name = av[0];
  if ((frv = fork()) == -1)
    return (-42);
  else if (frv == 0 && execve(name, av, env->tabi))
    exit(1);
  else
    {
      waitpid(frv, &status, 0);
      env->exit_statu = treat_status(status);
    }
  return (env->exit_statu);
}

int		my_builtins(char **av, t_env *env)
{
  char		*built[NB_BUILT + 1];
  t_builtfc	fcts[NB_BUILT + 1];
  int		i;

  init_builtins(built);
  init_builtins_fct(fcts);
  i = 0;
  while (built[i] != NULL && my_strcmp(av[0], built[i]) != 0)
    ++i;
  return (fcts[i](av, env));
}

char		**add_options(char **av, t_env *env)
{
  int		i;
  int		j;
  char		**end;
  char		**opts;
  char		*tmp;

  if (my_strcmp(av[0], LS) != 0
      || (tmp = my_getenv(LS_OPTIONS, env->tabi)) == NULL
      || !(opts = my_str_to_wordtab(tmp, " \t", 1)))
    return (av);
  free(tmp);
  i = my_strtablen(av) + my_strtablen(opts) + 1;
  if ((end = my_malloc(i * sizeof(char *))) == NULL)
    return (av);
  i = -1;
  while (av[++i])
    end[i] = my_strdup(av[i]);
  j = 0;
  while (opts[j])
    end[i++] = my_strdup(opts[j++]);
  end[i] = NULL;
  free_tab(av);
  free_tab(opts);
  return (end);
}
