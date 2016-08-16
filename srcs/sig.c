/*
** sig.c for catch sig  in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Thu Apr  7 11:59:41 2016 Bertrand Vautrin
** Last update Sun Jun  5 13:24:37 2016 Florian Vincent
*/

#include "minishell.h"

int	treat_status(int status)
{
  int	sig;
  int	ret;

  ret = 0;
  if (WIFSIGNALED(status))
    {
      sig = WTERMSIG(status);
      if (sig == SIGSEGV)
	{
	  my_puterr(SEGMENTATION_FAULT);
	  ret = SEGFAULT_EXIT;
	  my_exit(ret);
	}
      else if (sig == SIGFPE)
	{
	  my_puterr(FLOATING_EXCEPTION);
	  ret = FLOATING_EXCEPT_EXIT;
	  my_exit(ret);
	}
    }
  else if (WIFEXITED(status))
    ret = WEXITSTATUS(status);
  return (ret);
}

void	ctrl_c2(int sig)
{
  my_printf("\n");
  (void)sig;
}

void	ctrl_c(int sig)
{
  my_printf("\n");
  my_prompt();
  (void)sig;
}
