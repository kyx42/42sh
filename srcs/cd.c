/*
** cd.c for cd functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Fri Mar 25 12:51:13 2016 Bertrand Vautrin
** Last update Sun Jun  5 16:09:04 2016 Timothée Puentes
*/

#include "minishell.h"

static int	check_permission(const char *folder)
{
  struct stat	st;

  if (stat(folder, &st))
    {
      my_puterr(folder);
      my_puterr(CD_NO_SUCH_FILE);
      return (-1);
    }
  if (!S_ISDIR(st.st_mode))
    {
      my_puterr(folder);
      my_puterr(CD_NO_DIR);
      return (-1);
    }
  if (!(st.st_mode & 0400))
    {
      my_puterr(folder);
      my_puterr(CD_PERMISSION_DENIED);
      return (-1);
    }
  return (0);
}

static int	my_chdir(const char *dest, t_env *env, char **oldpwd)
{
  char		*tmp;
  int		ret;

  tmp = getcwd(NULL, 0);
  if (!dest || check_permission(dest))
    return (-1);
  if ((ret = chdir(dest)) == -1)
    {
      my_puterr(dest);
      my_puterr(CD_NO_DIR);
    }
  else
    {
      if (*oldpwd)
	free(*oldpwd);
      if (tmp)
	{
	  *oldpwd = my_strdup(tmp);
	  free(tmp);
	}
      my_setenv(PWD, (tmp = getcwd(NULL, 0)), env);
    }
  if (tmp != NULL)
    free(tmp);
  return (ret);
}

int	my_cd(char *dest, t_env *env)
{
  char	*tmp;
  int	ret;
  static	char *oldpwd = NULL;

  tmp = NULL;
  if (!dest || !my_strcmp(dest, CD_TILDE))
    {
      if ((tmp = my_getenv(HOME, env->tabi)) == NULL)
	ret = my_puterr(CD_HOME_NOT_SET);
      else
	ret = my_chdir(tmp, env, &oldpwd);
    }
  else if (my_strcmp(dest, CD_DASH) == 0)
    ret = my_chdir(oldpwd, env, &oldpwd);
  else
    ret = my_chdir(dest, env, &oldpwd);
  if (tmp != NULL)
    free(tmp);
  return (ret);
}
