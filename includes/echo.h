/*
** echo.h for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed May 25 15:06:27 2016 vincent mesquita
** Last update Sun Jun  5 16:26:34 2016 Timothée Puentes
*/

#ifndef ECHO_H_
# define ECHO_H_

# define WRONG_OPTION	"Error:"

# define ESCAPE_LEN	3
# define ESCAPE_NBR	12
# define N_OPTION	'n'
# define E_OPTION	'e'
# define CE_OPTION	'E'
# define DASH		'-'

# define HEXADECIMAL	"0123456789ABCDEF"
# define OCTAL		"01234567"

typedef struct		s_echo
{
  char			n_option;
  char			e_option;
}			t_echo;

typedef void (fptr)(char *str, unsigned int *i);

typedef struct		s_backslash_escape
{
  char			*flag;
  fptr			*fptr;
}			t_backslash_escape;

void	my_init_backslash_escape_tab(t_backslash_escape tabi[ESCAPE_NBR]);
void	my_print_backslash_esc(char *escape,
			       t_backslash_escape tabi[ESCAPE_NBR],
			       char *str,
			       unsigned int *index);
void	my_backslash(char *str, unsigned int *i);
void	my_backslash_a(char *str, unsigned int *i);
void	my_backslash_b(char *str, unsigned int *i);
void	my_backslash_c(char *str, unsigned int *i);
void	my_backslash_e(char *str, unsigned int *i);
void	my_backslash_f(char *str, unsigned int *i);
void	my_backslash_n(char *str, unsigned int *i);
void	my_backslash_r(char *str, unsigned int *i);
void	my_backslash_t(char *str, unsigned int *i);
void	my_backslash_v(char *str, unsigned int *i);
void	my_backslash_bi(char *str, unsigned int *i);
void	my_backslash_hex(char *str, unsigned int *i);

#endif /* !ECHO_H_ */
