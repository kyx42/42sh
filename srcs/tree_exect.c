/*
** tree_exect.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 15:31:19 2016 Bertrand Vautrin
** Last update Sun Jun  5 15:50:24 2016 Florian Vincent
*/

#include "minishell.h"

void		init_exect_tab(t_tree_exect *tab)
{
  tab[0] = &suit_exect_fct;
  tab[1] = &or_exect_fct;
  tab[2] = &and_exect_fct;
  tab[3] = &pipe_exect_fct;
  tab[4] = &double_right_red_exect_fct;
  tab[5] = &right_red_exect_fct;
  tab[6] = &double_left_red_exect_fct;
  tab[7] = &left_red_exect_fct;
  tab[8] = NULL;
}

int		my_tree_exect(t_tree *tree, t_env *env, char **sep)
{
  int		ret;
  int		i;
  t_tree_exect	fct[9];

  init_exect_tab(fct);
  if (tree == NULL)
    ret = 1;
  else if ((i = is_separator2(tree->data, sep)) < 0)
    {
      ret = my_normal_exect_command(tree->data, env, 0);
      env->exit_statu = ret;
    }
  else
    {
      ret = fct[i](tree, env, sep);
      if (env->pipe != 0)
	{
	  env->exit_statu = env->pipe_value % 255;
	  env->pipe = 0;
	  env->pipe_value = 0;
	}
    }
  return (ret);
}
