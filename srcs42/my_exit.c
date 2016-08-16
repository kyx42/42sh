/*
** my_exit.c for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Jun  2 21:13:27 2016 vincent mesquita
** Last update Thu Jun  2 21:14:38 2016 vincent mesquita
*/

#include "minishell.h"

void		my_exit(int value)
{
  if (!isatty(STDIN_FILENO))
    exit(value);
}
