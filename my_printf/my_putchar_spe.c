/*
** my_putchar.c for lib in /home/truong_j/rendu/Piscine_C_J07/lib/my
**
** Made by jonathan truong
** Login   <truong_j@epitech.net>
**
** Started on  Tue Oct  6 09:35:27 2015 jonathan truong
** Last update Fri Apr  8 14:24:28 2016 Bertrand Vautrin
*/

#include <unistd.h>

void	my_putchar_spe(char c, int *ccp)
{
  write(1, &c, 1);
  *ccp = *ccp + 1;
}
