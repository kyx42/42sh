/*
** exect_fcts.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue May  3 16:27:46 2016 Bertrand Vautrin
** Last update Sun Jun  5 16:58:59 2016 Timothée Puentes
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

int		and_exect_fct(t_tree *tree, t_env *env,
			       char **sep)
{
  int		ret;
  int		save[2];

  save[0] = dup(0);
  save[1] = dup(1);
  ret = my_tree_exect(tree->left, env, sep);
  reset_fd(save);
  if (ret == 0)
    ret = my_tree_exect(tree->right, env, sep);
  return (ret);
}

int		or_exect_fct(t_tree *tree, t_env *env,
			       char **sep)
{
  int		ret;
  int		save[2];

  save[0] = dup(0);
  save[1] = dup(1);
  ret = my_tree_exect(tree->left, env, sep);
  reset_fd(save);
  if (ret != 0)
    ret = my_tree_exect(tree->right, env, sep);
  return (ret);
}

static void	my_dup(int *fd, int flag)
{
  if (flag)
    {
      close(fd[0]);
      dup2(fd[1], 1);
      close(fd[1]);
    }
  else
    {
      close(fd[1]);
      dup2(fd[0], 0);
      close(fd[0]);
    }
}

int		pipe_exect_fct(t_tree *tree, t_env *env,
			       char **sep)
{
  int		fd[2];
  int		ret;
  int		rv;
  pid_t		pid;

  env->pipe = 1;
  pipe(fd);
  if ((pid = fork()) == -1)
    return (-42);
  else if (pid == 0)
    {
      my_dup(fd, 1);
      exit((ret = my_tree_exect(tree->left, env, sep)));
    }
  my_dup(fd, 0);
  ret = my_tree_exect(tree->right, env, sep);
  close(0);
  if (is_separator2(tree->right->data, sep) != 3)
     waitpid(pid, &rv, 0);
  if (rv)
    {
      ret = rv;
      env->pipe_value = rv;
    }
  else if (ret)
    env->pipe_value = ret;
  return (ret);
}
