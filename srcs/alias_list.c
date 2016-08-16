/*
** alias_list.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/alias
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue May 31 20:55:59 2016 vincent mesquita
** Last update Fri Jun  3 17:29:09 2016 Timothée Puentes
*/

#include "minishell.h"

t_alias_list		*create_alias(void)
{
  t_alias_list		*root;

  if (!(root = my_malloc(sizeof(*root))))
    return (NULL);
  root->next = root;
  root->prev = root;
  root->data = NULL;
  return (root);
}

int			my_add_alias(t_alias_list *root,
				     t_alias_info *ai)
{
  t_alias_list		*new;
  t_alias_list		*current;

  if (!(new = my_malloc(sizeof(*new))))
    return (-1);
  current = root->prev;
  new->data = ai;
  new->next = root;
  new->prev = current;
  current->next = new;
  root->prev = new;
  return (0);
}

static void		my_free_alias_info(t_alias_info *ai)
{
  if (ai->alias_name)
    free(ai->alias_name);
  free_tab(ai->alias);
  free(ai);
}

void			my_delete_alias(t_alias_list *root,
					t_alias_list *current)
{
  if (root && current && current != root)
    {
      current->next->prev = current->prev;
      current->prev->next = current->next;
      my_free_alias_info(current->data);
      free(current);
    }
}

void			my_free_alias(t_alias_list *root)
{
  t_alias_list		*tmp;
  t_alias_list		*current;

  if (root)
    {
      current = root->next;
      while (current != root)
	{
	  tmp = current;
	  current = current->next;
	  my_free_alias_info(tmp->data);
	  free(tmp);
	}
      free(root);
    }
}
