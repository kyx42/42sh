/*
** fcts_display3.c for display fonctions part 3 in /home/vautri_b/Projets/Projets_S1/Printf/My_Printf
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Mon Nov  9 11:43:02 2015 Bertrand Vautrin
** Last update Fri Apr  8 14:33:22 2016 Bertrand Vautrin
*/

#include <stdarg.h>
#include "my_printf.h"

void	my_va_char_printed(va_list ap, int *ccp)
{
  *va_arg(ap, int *) = *ccp;
}
