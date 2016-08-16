/*
** build_tree.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 15:21:17 2016 Bertrand Vautrin
** Last update Tue May 24 15:52:52 2016 vincent mesquita
*/

#include "minishell.h"

void		red_build_tree(char *str, char **sep, int i, t_tree *tree)
{
  char		*tmp;

  tree->data = my_strdup(sep[i]);
  tmp = red_cut(str, sep[i], NULL);
  tree->right = build_tree(tmp, sep);
  tmp = red_cut(str, sep[i], tmp);
  tree->left = build_tree(tmp, sep);
}

t_tree		*build_tree(char *str, char **sep)
{
  t_tree	*tree;
  int		i;

  if ((tree = my_malloc(sizeof(*tree))) == NULL)
    return (NULL);
  if ((i = is_separator_in(str, sep)) >= 0 && i <= 3)
    {
      tree->data = my_strdup(sep[i]);
      tree->left = build_tree(cut(str, sep[i], 0), sep);
      tree->right = build_tree(cut(str, sep[i], 1), sep);
    }
  else if (i > 3)
    red_build_tree(str, sep, i, tree);
  else
    {
      tree->data = my_strdup(str);
      tree->right = NULL;
      tree->left = NULL;
    }
  return (tree);
}
