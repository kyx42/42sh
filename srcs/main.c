/*
** main.c for minishell2 in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2/srcs
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Tue Mar 22 13:16:23 2016 Bertrand Vautrin
** Last update Sat Jun  4 15:21:02 2016 Timothée Puentes
*/

#include <time.h>

#include "minishell.h"

void	free_tab(char **tab)
{
  int	i;

  if (tab != NULL)
    {
      i = 0;
      while (tab[i])
	free(tab[i++]);
      free(tab);
    }
}

void	my_putstrtab(char **env)
{
  int	i;

  i = -1;
  while (env[++i])
    my_printf("%s\n", env[i]);
}

void	minishell(t_env *env)
{
  char	*entry;
  int	ret;

  env->p_size = my_prompt();
  ret = 0;
  while (ret != EXIT_VALUE &&
	 env->exit_call == 0 && (entry = getch_next(env)) != NULL)
    {
      ret = my_tree_exect_command(entry, env);
      add_to_list(env->histo, entry);
      free(entry);
      if (env->exit_call == 0 && ret != EXIT_VALUE)
	env->exit_statu = ret;
      if (ret != EXIT_VALUE && env->exit_call == 0)
	env->p_size = my_prompt();
    }
  if (ret != EXIT_VALUE)
    my_printf(EXIT_MESSAGE);
}

int	main(int ac, char **av, char **ev)
{
  t_env	env;

  srand(time(NULL));
  (void)ac;
  (void)av;
  env.exit_call = 0;
  env.exit_statu = 0;
  if (!(env.tabi = my_strtabdup(ev))
      || (isatty(STDIN_FILENO) && signal(SIGINT, &ctrl_c) == SIG_ERR)
      || !(env.alias_root = create_alias())
      || load_42shrc(&env) == -1
      || (env.histo = create_my_list()) == NULL)
    return (-1);
  set_termios(0, &env);
  minishell(&env);
  free_tab(env.tabi);
  env.exit_statu = env.exit_statu % 256;
  my_free_alias(env.alias_root);
  set_termios(1, &env);
  return (env.exit_statu);
}
