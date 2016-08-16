/*
** get_next_line.h for  in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Apr  8 01:34:18 2016 vincent mesquita
** Last update Fri May 27 14:17:51 2016 vincent mesquita
*/

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif /* !READ_SIZE */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H
char	*get_next_line(const int fd);

typedef	struct	s_get_next_line
{
  char		*buffer;
  char		*line;
  int		end;
}		t_get_next_line;

typedef	struct	s_need
{
  char		*cpy;
  char		*str2;
  int		h;
}		t_need;
#endif /* !GET_NEXT_LINE_H_ */
