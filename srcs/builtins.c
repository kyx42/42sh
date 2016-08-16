/*
** builtins.c for builtins functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Fri Mar 25 11:52:56 2016 Bertrand Vautrin
** Last update Sun Jun  5 16:07:33 2016 Timothée Puentes
*/

#include "minishell.h"

int	built_env(char **av, t_env *env)
{
  (void)av;
  my_putstrtab(env->tabi);
  return (0);
}

int	built_setenv(char **av, t_env *env)
{
  int	len;

  if ((len = my_strtablen(av)) < 2)
    my_putstrtab(env->tabi);
  else if (len > 3)
    {
      my_puterr(SETENV_ARGS_ERR);
      return (1);
    }
  else if (len == 2)
    my_setenv(av[1], "\0", env);
  else
    my_setenv(av[1], av[2], env);
  return (0);
}

int	built_unsetenv(char **av, t_env *env)
{
  int	i;

  if (my_strtablen(av) == 1)
    {
      my_puterr(UNSETENV_ARGS_ERR);
      return (1);
    }
  else
    {
      i = 1;
      while (av[i])
	my_unsetenv(av[i++], env);
    }
  return (0);
}

int	built_exit(char **av, t_env *env)
{
  int	ret;

  ret = 0;
  if (my_strtablen(av) > 2)
    ret = -1;
  else if (av[1])
    ret = is_num(av[1]);
  if (!ret)
    {
      env->exit_statu = my_get_nbr(av[1]);
      env->exit_call = 1;
    }
  if (ret == -1)
    my_puterr(EXIT_ERR);
  else if (ret == -2)
    my_puterr("exit: Badly formed number.\n");
  else
    ret = env->exit_statu;
  return (ret);
}

int	built_cd(char **av, t_env *env)
{
  int	len;
  int	ret;

  if ((len = my_strtablen(av)) > 2)
    {
      my_puterr(CD_ERR);
      return (1);
    }
  else if (len == 1 && my_strcmp(av[0], DOTDOT) == 0)
    ret = my_cd(DOTDOT, env);
  else
    ret = my_cd(av[1], env);
  return (ret);
}
