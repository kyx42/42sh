/*
** tree_check_fcts2.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed May  4 12:00:58 2016 Bertrand Vautrin
** Last update Sun Jun  5 15:49:48 2016 Florian Vincent
*/

#include "minishell.h"

int		double_right_red_check_fct(t_tree *tree, char **sep)
{
  int		ret;
  int		i;

  ret = 0;
  if (is_empty(tree->right->data) == 0)
    ret = my_puterr(NAME_RED);
  else if (ret == 0 && is_empty(tree->left->data) == 0)
    ret = my_puterr(NULL_CMD);
  else if (ret == 0 &&
	   ((i = is_separator2(tree->left->data, sep)) == 4 || i == 5))
    ret = my_puterr(O_REDIR);
  return (ret);
}

int		right_red_check_fct(t_tree *tree, char **sep)
{
  int		ret;
  int		i;

  ret = 0;
  if (is_empty(tree->right->data) == 0)
    ret = my_puterr(NAME_RED);
  else if (ret == 0 && is_empty(tree->left->data) == 0)
    ret = my_puterr(NULL_CMD);
  else if (ret == 0 &&
	   ((i = is_separator2(tree->left->data, sep)) == 4 || i == 5))
    ret = my_puterr(O_REDIR);
  return (ret);
}

int		double_left_red_check_fct(t_tree *tree, char **sep)
{
  int		ret;
  int		i;

  ret = 0;
  if (is_empty(tree->right->data) == 0)
    ret = my_puterr(NAME_RED);
  else if (ret == 0 && is_empty(tree->left->data) == 0)
    ret = my_puterr(NULL_CMD);
  else if (ret == 0 &&
	   ((i = is_separator2(tree->left->data, sep)) == 6 || i == 7))
    ret = my_puterr(I_REDIR);
  return (ret);
}

int		left_red_check_fct(t_tree *tree, char **sep)
{
  int		ret;
  int		i;

  ret = 0;
  if (is_empty(tree->right->data) == 0)
    ret = my_puterr(NAME_RED);
  else if (ret == 0 && is_empty(tree->left->data) == 0)
    ret = my_puterr(NULL_CMD);
  else if (ret == 0 &&
	   ((i = is_separator2(tree->left->data, sep)) == 6 || i == 7))
    ret = my_puterr(I_REDIR);
  return (ret);
}
