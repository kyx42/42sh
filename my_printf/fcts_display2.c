/*
** fcts_display2.c for display fonction for my_printf in /home/vautri_b/Projets/Projets_S1/Printf/My_Printf/srcs
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Fri Nov  6 11:48:09 2015 Bertrand Vautrin
** Last update Fri Apr  8 14:32:53 2016 Bertrand Vautrin
*/

#include <stdarg.h>
#include "my_printf.h"

void		my_va_hex_maj(va_list ap, int *ccp)
{
  my_put_nbr_base_spe(va_arg(ap, unsigned int), "0123456789ABCDEF", ccp);
}

void		my_va_bin(va_list ap, int *ccp)
{
  my_put_nbr_base_spe(va_arg(ap, unsigned int), "01", ccp);
}

void		my_va_oct(va_list ap, int *ccp)
{
  my_put_nbr_base_spe(va_arg(ap, unsigned int), "01234567", ccp);
}

void		my_va_string_S(va_list ap, int *ccp)
{
  my_putstr_spe_S(va_arg(ap, char *), ccp);
}

void		my_va_ptr(va_list ap, int *ccp)
{
  void		*ptr;

  ptr = va_arg(ap, void *);
  if (ptr == 0)
    my_putstr_spe("(nil)", ccp);
  else
    {
       my_putstr_spe("0x", ccp);
       my_put_nbr_base_spe_long((long)ptr, "0123456789abcdef", ccp);
    }
}
