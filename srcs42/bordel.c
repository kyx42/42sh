/*
** bordel.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu May 19 15:43:20 2016 Bertrand Vautrin
** Last update Sun Jun  5 16:05:49 2016 Timothée Puentes
*/

#include "minishell.h"

static char	**my_search_alias(char ** av,
				 t_alias_list *root)
{
  t_alias_list	*current;
  char		**new;

  if (!root || root->next == root)
    return (av);
  current = root->next;
  while (current != root)
    {
      if (my_strcmp(av[0], current->ALIAS_NAME) == 0)
	{
	  if (!(new = my_wordtab_cat(current->XALIAS, &av[1], 0)))
	    return (av);
	  free_tab(av);
	  return (new);
	}
      current = current->next;
    }
  return (av);
}

int		my_normal_exect_command(char *str, t_env *env, int flag)
{
  char		**av;
  char		**path;
  char		*tmp;
  int		ret;

  tmp = NULL;
  if ((av = my_str_to_wordtab(str, " \t", 1)) == NULL)
    return (1);
  path = init_path(env->tabi);
  av = my_search_alias(av, env->alias_root);
  if (!(av = my_globing(av)))
    return (1);
  av = add_options(av, env);
  if ((ret = check_command(av, path, &tmp)) == 0)
      ret = my_exect(av, env, tmp);
  else if (ret == 2)
      ret = my_builtins(av, env);
  if (tmp != NULL)
    free(tmp);
  free_tab(av);
  free_tab(path);
  (void)(flag);
  if (ret < 0)
    return (1);
  return (ret % 255);
}

int	is_empty(char *str)
{
  int	i;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  if (str[i] == 0)
    return (0);
  return (-1);
}

int	get_input(char *end)
{
  int	pipefd[2];
  char	*tmp;

  if (pipe(pipefd) == -1)
    return (0);
  my_printf("? ");
  while ((tmp = get_next_line(0)) != NULL && my_strcmp(tmp, end) != 0)
    {
      (void)(write(pipefd[1], tmp, my_strlen(tmp)));
      (void)(write(pipefd[1], "\n", 1));
      my_printf("? ");
      free(tmp);
    }
  close(pipefd[1]);
  if (tmp != NULL)
    free(tmp);
  return (pipefd[0]);
}
