/*
** suit_exec_fct.c for suit_exec_fct in /home/vincen_s/rendu/PSU_2015_42sh/srcs42
** 
** Made by Florian Vincent
** Login   <vincen_s@epitech.net>
** 
** Started on  Sun Jun  5 15:02:37 2016 Florian Vincent
** Last update Sun Jun  5 15:04:22 2016 Florian Vincent
*/

#include "minishell.h"

int		suit_exect_fct(t_tree *tree, t_env *env,
			       char **sep)
{
  int		ret;
  int		save[2];

  save[0] = dup(0);
  save[1] = dup(1);
  ret = my_tree_exect(tree->left, env, sep);
  reset_fd(save);
  ret = my_tree_exect(tree->right, env, sep);
  return (ret);
}
