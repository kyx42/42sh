/*
** create_list.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon May 30 17:16:01 2016 vincent mesquita
** Last update Mon May 30 17:30:10 2016 vincent mesquita
*/

#include "minishell.h"

t_list		*create_list(void)
{
  t_list	*root;

  if (!(root = my_malloc(sizeof(*root))))
    return (NULL);
  root->data = 0;
  root->next = root;
  root->prev = root;
  return (root);
}

int		my_add_to_end_list(t_list *root,
				   char data)
{
  t_list	*new;
  t_list	*current;

  if (!root || !(new = my_malloc(sizeof(*new))))
    return (-1);
  new->data = data;
  current = root->prev;
  new->next = root;
  new->prev = current;
  current->next = new;
  root->prev = new;
  return (0);
}

void		my_free_list(t_list *root)
{
  t_list	*current;
  t_list	*tmp;

  if (root)
    {
      current = root->next;
      while (current != root)
	{
	  tmp = current;
	  current = current->next;
	  free(tmp);
	}
      free(root);
    }
}
