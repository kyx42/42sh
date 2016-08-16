/*
** historique.c for historique in /home/peixot_b/Depot/PSU/PSU_2015_42sh/srcs
**
** Made by Peixoto Benjamin
** Login   <peixot_b@epitech.net>
**
** Started on  Tue May 31 14:12:29 2016 Peixoto Benjamin
** Last update Sun Jun  5 20:13:39 2016 Timothée Puentes
*/

#include <stdlib.h>
#include "minishell.h"

t_histo		*create_my_list(void)
{
  t_histo	*racine;

  if ((racine = malloc (sizeof(*racine))) != NULL)
    {
      racine->prec = racine;
      racine->suiv = racine;
    }
  return (racine);
}

int		check_historique(const char *str)
{
  int		c;

  if (str == NULL)
    return (0);
    c = 0;
  while (str[c])
    {
      if (str[c] != ' ' && str[c] != ';')
	return (1);
      c += 1;
    }
  return (0);
}

void		add_to_list(t_histo *element, char *str)
{
  t_histo	*new_elem;

  if (check_historique(str) == 1 &&
      (new_elem = malloc(sizeof(*new_elem))) != NULL)
    {
      new_elem->entry = my_strdup(str);
      new_elem->prec = element->prec;
      new_elem->suiv = element;
      element->prec->suiv = new_elem;
      element->prec = new_elem;
    }
}

void		free_my_list(t_histo *root)
{
  t_histo	*current;
  t_histo	*tmp;

  if (root)
    {
      current = root->suiv;
      while (current != root)
	{
	  tmp = current;
	  current = current->suiv;
	  free(tmp);
	}
      free(root);
    }
}

void		delete_my_list(t_histo *current)
{
  t_histo	*to_supp;

  if (current && current->suiv != current)
    {
      to_supp = current->prec;
      to_supp->prec->suiv = current;
      current->prec = to_supp->prec;
      free(to_supp);
    }
}
