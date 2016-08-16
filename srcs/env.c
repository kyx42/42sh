/*
** env.c for env functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu Mar 24 16:41:53 2016 Bertrand Vautrin
** Last update Sun Jun  5 16:09:48 2016 Timothée Puentes
*/

#include "minishell.h"

int	change_env(const char *name, const char *value, t_env *env)
{
  int	i;
  char	*tmp;
  char	*line;

  if ((tmp = my_strcat(name, "=")) == NULL
      || (line = my_strcat(tmp, value)) == NULL)
    return (-1);
  free(tmp);
  i = 0;
  while (my_strcmp(name, env->tabi[i]) == -1)
    i++;
  free(env->tabi[i]);
  env->tabi[i] = line;
  return (0);
}

int	add_env(const char *name, const char *value, t_env *env)
{
  int	i;
  char	*tmp;
  char	*line;
  char	**new;

  if ((new = my_malloc((my_strtablen(env->tabi) + 2)
		       * sizeof(char *))) == NULL)
    return (-1);
  i = 0;
  while (env->tabi[i])
    {
      if ((new[i] = my_strdup(env->tabi[i])) == NULL)
	return (-1);
      i++;
    }
  if ((tmp = my_strcat(name, "=")) == NULL
      || (line = my_strcat(tmp, value)) == NULL)
    return (-1);
  free(tmp);
  new[i++] = line;
  new[i] = NULL;
  free_tab(env->tabi);
  env->tabi = new;
  return (0);
}

void	my_setenv(char *name, char *value, t_env *env)
{
  int	i;

  i = 0;
  if (!my_alphanumeric(name))
    {
      my_puterr(SETENV_WRONG_VALUE);
      return ;
    }
  while (env->tabi[i] != NULL && my_strcmp(name, env->tabi[i])
	 == -1)
    i++;
  if (env->tabi[i] != NULL)
    change_env(name, value, env);
  else
    add_env(name, value, env);
}

char	*my_getenv(const char *str, char **ev)
{
  char	*var;
  int	i;

  i = 0;
  while (ev[i] != NULL && my_strcmp(str, ev[i]) == -1)
    i = i + 1;
  if (ev[i] == NULL || (var = my_nstrdup(ev[i], my_strlen(str) + 1))
      == NULL)
    return (NULL);
  return (var);
}

int	my_unsetenv(char *str, t_env *env)
{
  int	i;
  int	j;
  char	**new;

  if ((new = my_malloc((my_strtablen(env->tabi) + 1)
		       * sizeof(char *))) == NULL)
    return (-1);
  i = -1;
  j = 0;
  while (env->tabi[++i])
    if (my_strcmp(str, env->tabi[i]) == -1)
      new[j++] = my_strdup(env->tabi[i]);
  new[j] = NULL;
  free_tab(env->tabi);
  env->tabi = new;
  return (0);
}
