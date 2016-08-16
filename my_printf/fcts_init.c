/*
** fcts_init.c for initialisation fonctions for disp_stdarg in /home/vautri_b/Projets/Projets_S1/Printf/Bootstrap/PSU_2015_my_printf_bootstrap/srcs
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed Nov  4 20:24:31 2015 Bertrand Vautrin
** Last update Thu Nov 12 13:22:03 2015 Bertrand Vautrin
*/

#include "my_printf.h"

t_fct		_init_tab_case(char flag, ptrfc fct)
{
  t_fct		tmp;

  tmp.flag = flag;
  tmp.fct = fct;
  return (tmp);
}

void		_init_tab(t_fct *tab)
{
  tab[0] = _init_tab_case('c', &my_va_char);
  tab[1] = _init_tab_case('s', &my_va_string);
  tab[2] = _init_tab_case('i', &my_va_int);
  tab[3] = _init_tab_case('d', &my_va_int);
  tab[4] = _init_tab_case('u', &my_va_u_int);
  tab[5] = _init_tab_case('x', &my_va_hex);
  tab[6] = _init_tab_case('X', &my_va_hex_maj);
  tab[7] = _init_tab_case('b', &my_va_bin);
  tab[8] = _init_tab_case('o', &my_va_oct);
  tab[9] = _init_tab_case('S', &my_va_string_S);
  tab[10] = _init_tab_case('p', &my_va_ptr);
  tab[11] = _init_tab_case('n', &my_va_char_printed);
}
