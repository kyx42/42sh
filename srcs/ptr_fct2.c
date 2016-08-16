/*
** ptr_fct2.c for  in /home/puente_t/rendu/PSU/PSU_2015_42sh/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Sun Jun  5 16:49:37 2016 Timothée Puentes
** Last update Sun Jun  5 16:52:07 2016 Timothée Puentes
*/

#include "minishell.h"

char		*my_add_char(char *line, char c, int idx)
{
  int		i;
  char		*n_l;
  int		j;

  i = 0;
  if (!line || idx < 0 ||
      (n_l = my_malloc(my_strlen(line) + 2)) == NULL)
    return (NULL);
  while (line[i] && i != idx)
    {
      n_l[i] = line[i];
      i++;
    }
  j = i;
  n_l[j++] = c;
  while (line[i])
    n_l[j++] = line[i++];
  n_l[j] = 0;
  return (n_l);
}

char		*my_back(int *idx, char *line, t_env *env)
{
  if (*idx < 0 || *idx == 0)
      return (line);
  *idx -= 1;
  my_putchar('\b');
  (void)env;
  return (line);
}

char		*my_forward(int *idx, char *line, t_env *env)
{
  if (*idx < 0 || *idx >= my_strlen(line))
    return (line);
  my_putchar(line[*idx]);
  *idx += 1;
  (void)env;
  return (line);
}

void		change_word(t_env *env, char *line, int *idx)
{
  int		i;

  i = -1;
  while (++i < my_strlen(line) - *idx)
    my_printf("%s", env->right);
  i = (my_strlen(line) + env->p_size + 1) / env->width;
  while (--i >= 0)
    my_printf("%s", env->up);
  i = (my_strlen(line) + env->p_size + 1) % env->width;
  while (++i < env->p_size + 2)
    my_printf("%s", env->right);
  while (--i > env->p_size + 1)
    my_printf("%s", env->left);
  i = 0;
  while (i++ < my_strlen(line))
    my_printf(" ");
  i = (my_strlen(line) + env->p_size + 1) / env->width;
  while (--i >= 0)
    my_printf("%s", env->up);
  i = (my_strlen(line) + env->p_size + 1) % env->width;
  while (++i < env->p_size + 2)
    my_printf("%s", env->right);
  while (--i > env->p_size + 1)
    my_printf("%s", env->left);
}

char		*my_up(int *idx, char *line, t_env *env)
{
  (void)env;
  if (env->curr->prec == env->histo)
    return (line);
  change_word(env, line, idx);
  if (line)
    free(line);
  env->curr = env->curr->prec;
  line = my_strdup(env->curr->entry);
  *idx = my_strlen(line);
  my_printf(line);
  return (line);
}
