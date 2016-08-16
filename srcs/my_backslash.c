/*
** my_backslah.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed May 25 16:15:39 2016 vincent mesquita
** Last update Sun Jun  5 13:32:37 2016 Florian Vincent
*/

#include "minishell.h"

void	my_backslash(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("\\");
  *i += 1;
}

void	my_backslash_a(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("\a");
  *i += 1;
}

void	my_backslash_b(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("\b");
  *i += 1;
}

void	my_backslash_c(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("");
  *i += 1;
}

void	my_backslash_e(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("\e");
  *i += 1;
}
