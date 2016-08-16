/*
** my_strlen.c for my_strlen in /home/vautri_b/Projets/Projets_S1/Printf/Bootstrap/PSU_2015_my_printf_bootstrap/srcs
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed Nov  4 13:06:57 2015 Bertrand Vautrin
** Last update Wed Nov  4 13:14:09 2015 Bertrand Vautrin
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
