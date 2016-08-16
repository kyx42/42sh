/*
** fcts_display.c for display fonctions in /home/vautri_b/Projets/Projets_S1/Printf/Bootstrap/PSU_2015_my_printf_bootstrap/srcs
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed Nov  4 20:21:03 2015 Bertrand Vautrin
** Last update Fri Apr  8 14:32:19 2016 Bertrand Vautrin
*/

#include <stdarg.h>
#include "my_printf.h"

void	my_va_char(va_list ap, int *ccp)
{
  my_putchar_spe(va_arg(ap, int), ccp);
}

void	my_va_int(va_list ap, int *ccp)
{
  my_put_nbr_spe(va_arg(ap, int), ccp);
}

void	my_va_string(va_list ap, int *ccp)
{
  my_putstr_spe(va_arg(ap, char *), ccp);
}

void	my_va_u_int(va_list ap, int *ccp)
{
  my_put_nbr_u_spe(va_arg(ap, unsigned int), ccp);
}

void	my_va_hex(va_list ap, int *ccp)
{
  my_put_nbr_base_spe_long(va_arg(ap, unsigned int), "0123456789abcdef", ccp);
}
