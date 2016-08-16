/*
** built_echo.c for built_echo.c in /home/vincen_s/rendu/PSU_2015_42sh/srcs
**
** Made by Florian Vincent
** Login   <vincen_s@epitech.net>
**
** Started on  Sun Jun  5 13:51:11 2016 Florian Vincent
** Last update Sun Jun  5 16:16:50 2016 Timothée Puentes
*/

#include "minishell.h"
#include "echo.h"

int		reset_options(t_echo *echo_option)
{
  echo_option->n_option = 0;
  echo_option->e_option = 1;
  return (-1);
}
