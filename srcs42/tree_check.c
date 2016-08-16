/*
** tree_check.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed May  4 11:19:56 2016 Bertrand Vautrin
** Last update Wed Jun  1 15:45:34 2016 Bertrand Vautrin
*/

#include "minishell.h"

void		init_check_fct(t_tree_check *tab)
{
  tab[0] = &suit_check_fct;
  tab[1] = &or_check_fct;
  tab[2] = &and_check_fct;
  tab[3] = &pipe_check_fct;
  tab[4] = &double_right_red_check_fct;
  tab[5] = &right_red_check_fct;
  tab[6] = &double_left_red_check_fct;
  tab[7] = &left_red_check_fct;
  tab[8] = NULL;
}

int		check_tree(t_tree *tree, char **sep)
{
  t_tree_check	fct[9];
  int		i;
  int		ret;

  ret = 0;
  if (tree->left != NULL)
    ret = check_tree(tree->left, sep);
  init_check_fct(fct);
  if (ret == 0 && (i = is_separator2(tree->data, sep)) < 0)
    return (0);
  if (ret == 0)
    ret = fct[i](tree, sep);
  if (ret == 0 && tree->right != NULL)
    ret = check_tree(tree->right, sep);
  return (ret);
}
