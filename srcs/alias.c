/*
** alias.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/alias
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue May 31 20:26:43 2016 vincent mesquita
** Last update Sun Jun  5 14:19:11 2016 Florian Vincent
*/

#include "minishell.h"

static void		my_show_w(char **alias)
{
  unsigned int		i;

  i = 0;
  if (!alias)
    {
      my_printf("\n");
      return ;
    }
  while (alias[i] && alias[i + 1])
    {
      my_printf("%s ", alias[i]);
      i += 1;
    }
  my_printf("%s\n", alias[i]);
}

static void		my_show_alias(t_alias_list *root)
{
  t_alias_list		*current;

  current = root->next;
  while (current != root)
    {
      my_printf("%s\t\t", current->ALIAS_NAME);
      my_show_w(current->XALIAS);
      current = current->next;
    }
}

static t_alias_list	*my_alias_definition(char *alias_name,
					     t_alias_list *root,
					     int print_flag)
{
  t_alias_list		*current;

  current = root->next;
  while (current != root)
    {
      if (my_strcmp(alias_name, current->ALIAS_NAME) == 0)
	{
	  if (print_flag == 1)
	    my_show_w(current->XALIAS);
	  return (current);
	}
      current = current->next;
    }
  return (NULL);
}

static int		my_add_new_alias(char **av,
					 t_alias_list *root)
{
  t_alias_info		*data;
  t_alias_list		*current;

  if (my_strtablen(av) == 2)
    {
      my_alias_definition(av[1], root, 1);
      return (0);
    }
  else if ((current = my_alias_definition(av[1], root, 0)))
    {
      free_tab(current->XALIAS);
      if ((current->XALIAS = my_strtabdup(&av[2])))
	{
	  my_delete_alias(root, current);
	  return (my_puterr(ALIAS_CHANGE_ERR));
	}
    }
  else if (!(data = malloc(sizeof(*data)))
	   || !(data->alias_name = my_strdup(av[1]))
	   || !(data->alias = my_strtabdup(&av[2]))
	   || my_add_alias(root, data) < 0)
    return (my_puterr(ALIAS_ERR));
  return (0);
}

int			built_alias(char **av, t_env *env)
{
  if (!env->alias_root)
    return (-1);
  if (my_strtablen(av) == 1)
    my_show_alias(env->alias_root);
  else
    my_add_new_alias(av, env->alias_root);
  return (0);
}
