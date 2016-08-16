/*
** tree_exect2.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 16:31:14 2016 Bertrand Vautrin
** Last update Sun Jun  5 15:10:02 2016 Florian Vincent
*/

#include "minishell.h"

static int	check_file(const char *str)
{
  struct stat	st;

  if (stat(str, &st))
    return (0);
  if ((st.st_mode & S_IFMT) == S_IFDIR)
    {
      my_puterr(str);
      return (my_puterr(IS_DIRE));
    }
  if (access(str, W_OK))
    {
      my_puterr(str);
      return (my_puterr(CD_PERMISSION_DENIED));
    }
  return (0);
}

int		double_right_red_exect_fct(t_tree *tree, t_env *env,
					   char **sep)
{
  int		flag;
  int		fd;
  int		ret;

  if (check_file(tree->right->data))
    return (1);
  flag = O_RDWR | O_APPEND;
  if (access(tree->right->data, F_OK))
    flag = flag | O_CREAT;
  fd = open(tree->right->data, flag, 0644);
  dup2(fd, 1);
  close(fd);
  ret = my_tree_exect(tree->left, env, sep);
  return (ret);
}

int		right_red_exect_fct(t_tree *tree, t_env *env,
				    char **sep)
{
  int		flag;
  int		fd;
  int		ret;

  if (check_file(tree->right->data))
    return (1);
  flag = O_RDWR | O_TRUNC;
  if (access(tree->right->data, F_OK))
    flag = flag | O_CREAT;
  fd = open(tree->right->data, flag, 0644);
  dup2(fd, 1);
  close(fd);
  ret = my_tree_exect(tree->left, env, sep);
  return (ret);
}

int		double_left_red_exect_fct(t_tree *tree, t_env *env,
					  char **sep)
{
  int		fd;
  int		ret;

  fd = get_input(tree->right->data);
  dup2(fd, 0);
  close(fd);
  ret = my_tree_exect(tree->left, env, sep);
  return (ret);
}

int		left_red_exect_fct(t_tree *tree, t_env *env,
				   char **sep)
{
  int		fd;
  int		ret;

  if ((fd = open(tree->right->data, O_RDONLY)) == -1)
    {
      my_puterr(tree->right->data);
      my_puterr(CD_NO_SUCH_FILE);
      return (1);
    }
  dup2(fd, 0);
  close(fd);
  ret = my_tree_exect(tree->left, env, sep);
  return (ret);
}
