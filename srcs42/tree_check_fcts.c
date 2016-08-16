/*
** tree_check_fcts.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed May  4 11:58:17 2016 Bertrand Vautrin
** Last update Mon May 30 15:42:04 2016 Bertrand Vautrin
*/

#include "minishell.h"

int		suit_check_fct(t_tree *tree, char **sep)
{
  (void)tree;
  (void)sep;
  return (0);
}

int		and_check_fct(t_tree *tree, char **sep)
{
  (void)sep;
  if (is_empty(tree->left->data) == 0 || is_empty(tree->right->data) == 0)
    return (my_puterr("Invalid null command.\n"));
  return (0);
}

int		or_check_fct(t_tree *tree, char **sep)
{
  (void)sep;
  if (is_empty(tree->left->data) == 0 || is_empty(tree->right->data) == 0)
    return (my_puterr("Invalid null command.\n"));
  return (0);
}

int		check_red_after_pipe(t_tree *tree, char **sep, int red)
{
  int		cur;
  int		next;

  next = 0;
  cur = 0;
  if (tree)
    cur = is_separator2(tree->data, sep);
  if (tree->right)
    next = is_separator2(tree->left->data, sep);
  if (red == 1 && (cur == 4 || cur == 5 || next == 4 || next == 5))
    return (-1);
  if (red == 0 && (cur == 6 || cur == 7 || next == 6 || next == 7))
    return (-1);
  return (0);
}

int		pipe_check_fct(t_tree *tree, char **sep)
{
  int		ret;

  ret = 0;
  if (is_empty(tree->left->data) == 0 || is_empty(tree->right->data) == 0)
    ret = my_puterr("Invalid null command.\n");
  else if (ret == 0 && check_red_after_pipe(tree->right, sep, 0))
    ret = my_puterr("Ambiguous input redirect.\n");
  else if (ret == 0 && check_red_after_pipe(tree->left, sep, 1))
    ret = my_puterr("Ambiguous output redirect.\n");
  return (ret);
}
