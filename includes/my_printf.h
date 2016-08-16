/*
** test.h for test printf.h in /home/vautri_b/Projets/Projets_S1/Printf/Bootstrap/PSU_2015_my_printf_bootstrap/srcs
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed Nov  4 17:39:11 2015 Bertrand Vautrin
** Last update Thu May 19 14:29:13 2016 Bertrand Vautrin
*/

#include <stdarg.h>
#include <stdio.h>

#ifndef _MY_PRINTF_H_
# define _MY_PRINTF_H_
# define NB_OF_FLAGS (12)

typedef void(*ptrfc)(va_list, int *);

typedef struct	s_fct
{
  char		flag;
  ptrfc		fct;
}		t_fct;

int		my_strlen(char *);
void		my_va_char(va_list, int *);
void		my_va_string(va_list, int *);
void		my_va_string_S(va_list, int *);
void		my_va_int(va_list, int *);
void		my_va_u_int(va_list, int *);
void		my_va_hex(va_list, int *);
void		my_va_hex_maj(va_list, int *);
void		my_va_bin(va_list, int *);
void		my_va_oct(va_list, int *);
void		my_va_ptr(va_list, int *);
void		my_va_char_printed(va_list, int *);
void		_init_tab(t_fct *);
void		my_putstr_spe(char *, int *);
void		my_putstr_spe_S(char *, int *);
void		my_putchar_spe(char, int *);
t_fct		_init_tab_case(char, ptrfc);
int		my_printf_2(char, va_list, t_fct *, int *);
int		my_printf(const char *, ...);

#endif /* _MY_PRINTF_H_ */
