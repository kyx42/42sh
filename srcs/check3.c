/*
** check3.c for functions check in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Sun Apr 10 12:09:35 2016 Bertrand Vautrin
** Last update Mon May 30 11:56:10 2016 vincent mesquita
*/

#include "minishell.h"

int		nis_empty(char *str, int i)
{
  while (str[i] == SPACE || str[i] == TAB)
    ++i;
  if (str[i] == 0 || str[i] == PIPE)
    return (-1);
  return (0);
}

int		check_redcmd(char *cmd, char *str)
{
  int		i;

  i = -1;
  while (cmd[++i])
    {
      if (is_separator(cmd[i], str) == 0)
	{
	  if (is_separator(cmd[++i], str) == 0)
	    ++i;
	  while (cmd[i] == SPACE || cmd[i] == TAB)
	    ++i;
	  if (cmd[i] != 0 && is_separator(cmd[i], str) != 0)
	    return (-1);
	  return (-2);
	}
    }
  return (0);
}

int		check_cmdred(char **cmd)
{
  int		i;
  int		ret;

  i = 0;
  ret = check_redcmd(cmd[i++], ">");
  while (ret != -1 && cmd[i + 1] != NULL)
    ret = check_redcmd(cmd[i++], "<>");
  if (ret >= 0)
    ret = check_redcmd(cmd[i], "<");
  if (ret == -1)
    my_puterr(AMBIGUOUS_OUTPUT_REDI);
  else if (ret == -2)
    my_puterr(MISSING_NAME_REDI);
  return (ret);
}

int		check_pipe(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      while (str[i] == SPACE || str[i] == TAB)
	++i;
      if (str[i] == PIPE)
	return (-1);
      while (str[i] != PIPE && str[i] != 0)
	++i;
      if (str[i] == PIPE && nis_empty(str, ++i) == -1)
	return (-1);
    }
  return (0);
}
