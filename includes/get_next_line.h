/*
** get_next_line.h for  in /home/puente_t/rendu/CPE_2015_getnextline
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Wed Jan  6 17:24:54 2016 puente_t
** Last update Tue May  3 18:09:44 2016 Bertrand Vautrin
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

char	*get_next_line(const int fd);
char	*stock(char *new, int mode);
char	*add_to_str(char *dest, char *ori);
char	*my_strdup(const char *src);
char	*my_strndup(const char *src, int n);
char	*my_strcat(char *dest, const char *src);
int	my_len(const char *str);
char	*mystrncpy(char *dest, const char *src, int n);
char	*mystrcpy(char *dest, const char *src);

# define GET_PLACE	((new[0] == 0) ? (c) : (c + 1))
# define GET_STOCK	((new[c] == 0) ? (c) : (c + 1))
# ifndef READ_SIZE
#  define READ_SIZE (10)
# endif /* !READ_SIZE */

#endif /* !GET_NEXT_LINE_H_ */
