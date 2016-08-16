/*
** tree_exect_fcts.c for exec_fcts.c in /home/vincen_s/rendu/PSU_2015_42sh/srcs42
** 
** Made by Florian Vincent
** Login   <vincen_s@epitech.net>
** 
** Started on  Sun Jun  5 15:20:28 2016 Florian Vincent
** Last update Sun Jun  5 15:20:28 2016 Florian Vincent
*/

#include "minishell.h"

int		and_exect_fct(t_tree *tree, t_env *env,
			      char **sep)
{
  int		ret;
  int		save[2];

  save[0] = dup(0);
  save[1] = dup(1);
  ret = 0;
  if (is_empty(tree->left->data))
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

static void	my_dup(int *fd, const int flag)
{
  if (flag)
    {
      close(fd[0]);
      (void)dup2(fd[1], 1);
      close(fd[1]);
    }
  else
    {
      close(fd[1]);
      (void)dup2(fd[0], 0);
      close(fd[0]);
    }
}

static void	pipe_value(int rv, int *ret, t_env *env)
{
  if (rv)
    {
      *ret = rv;
      env->pipe_value = rv;
    }
  else if (*ret)
    env->pipe_value = *ret;
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
    (void)waitpid(pid, &rv, 0);
  pipe_value(rv, &ret, env);
  return (ret);
}
