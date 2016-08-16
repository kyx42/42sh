/*
** test.c for test 42sh in /home/vautri_b/Projets/B2/C-ProgElem/CPE_2015_42h_vautri_b
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue Apr 26 15:06:02 2016 Bertrand Vautrin
** Last update Sun Jun  5 13:18:52 2016 Florian Vincent
*/

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

void		*my_malloc(const size_t size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      my_puterr(MALLOC_ERR);
      exit(1);
    }
  return (ptr);
}

void		reset_fd(int *fd)
{
  close(0);
  close(1);
  dup2(fd[0], 0);
  close(fd[0]);
  dup2(fd[1], 1);
  close(fd[1]);
}

void		free_tree(t_tree *tree)
{
  if (tree->left != NULL)
    free_tree(tree->left);
  free(tree->data);
  if (tree->right != NULL)
    free_tree(tree->right);
  free(tree);
}

int		my_tree_exect_command(char *entry, t_env *env)
{
  t_tree	*tree;
  char		*sep[9];
  int		ret;
  int		save[2];

  save[0] = dup(0);
  save[1] = dup(1);
  sep[0] = SEMICOLON;
  sep[1] = OR;
  sep[2] = AND;
  sep[3] = PIPE;
  sep[4] = DRIGHT_REDI;
  sep[5] = RIGHT_REDI;
  sep[6] = DLEFT_REDI;
  sep[7] = LEFT_REDI;
  sep[8] = NULL;
  tree = NULL;
  tree = build_tree(entry, sep);
  if (!(ret = check_tree(tree, sep)))
    ret = my_tree_exect(tree, env, sep);
  free_tree(tree);
  reset_fd(save);
  return (ret);
}
