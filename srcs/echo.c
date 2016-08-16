/*
** echo.c for 42sh in /home/vautri_b/Projets/B2/SystemeUnix/PSU_2015_42sh_tests
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu May 19 18:08:00 2016 Bertrand Vautrin
** Last update Sun Jun  5 13:59:10 2016 Florian Vincent
*/

#include "minishell.h"
#include "echo.h"

static int		check_options(const char *str, t_echo *echo_option)
{
  unsigned int		i;

  i = 1;
  while (str[i])
    {
      if (str[i] == N_OPTION)
	echo_option->n_option = 1;
      else
      	return (reset_options(echo_option));
      i += 1;
    }
  return (0);
}

static unsigned int	my_option(char * const av[], t_echo *echo_option)
{
  unsigned int		i;

  i = 1;
  while (av[i] && av[i][0] == DASH)
    {
      if (check_options(av[i], echo_option) < 0)
	return (i);
      i += 1;
    }
  return (i);
}

static void		my_put(char *str,
			       t_backslash_escape tab[ESCAPE_NBR],
			       int flag)
{
  unsigned int		i;
  char			backslash_esc[ESCAPE_LEN];

  i = 0;
  backslash_esc[0] = '\\';
  backslash_esc[2] = 0;
  while (str[i])
    {
      if (flag == 1 && str[i] == '\\')
	{
	  if ((backslash_esc[1] = str[i + 1]) == 'c')
	    return ;
	  my_print_backslash_esc(backslash_esc, tab, &str[i + 2], &i);
	}
      else
	my_putchar(str[i]);
      if (str[i])
	i += 1;
    }
}

static void		print_av(char **av,
				 int flag,
				 unsigned int i,
				 t_backslash_escape tab[ESCAPE_NBR])
{
  (void)(flag);
  while (av[i])
    {
      my_put(av[i++], tab, flag);
      if (av[i])
	my_printf(" ");
    }
}

int			built_echo(char **av, t_env *env)
{
  t_echo		echo_option;
  unsigned int		i;
  t_backslash_escape	tab[ESCAPE_NBR];

  (void)(env);
  echo_option.n_option = 0;
  echo_option.e_option = 1;
  my_init_backslash_escape_tab(tab);
  i = my_option(av, &echo_option);
  print_av(av, echo_option.e_option, i, tab);
  if (echo_option.n_option == 0)
    my_printf("\n");
  return (0);
}
