/*
** my_backslah2.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed May 25 16:22:52 2016 vincent mesquita
** Last update Thu May 26 14:43:44 2016 vincent mesquita
*/

#include "minishell.h"

void	my_backslash_f(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("\f");
  *i += 1;
}

void	my_backslash_n(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("\n");
  *i += 1;
}

void	my_backslash_r(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("\r");
  *i += 1;
}

void	my_backslash_t(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("\t");
  *i += 1;
}

void	my_backslash_v(char *str, unsigned int *i)
{
  (void)(str);
  my_printf("\v");
  *i += 1;
}
