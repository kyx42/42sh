/*
** my_str_to_woardtab.c for my_str_to_wordtab functions in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed Mar 23 12:56:01 2016 Bertrand Vautrin
** Last update Sun Jun  5 13:40:29 2016 Florian Vincent
*/

#include "minishell.h"

int		is_separator(const char c, const char *str)
{
  int		i;

  i = 0;
  while (str[i])
    if (c == str[i++])
      return (0);
  return (-1);
}

static int	find_nb_wd(char *str, char *separators, const int flag)
{
  int		i;
  int		nb;

  i = 0;
  nb = 1;
  while (flag == 1 && is_separator(str[i], separators) == 0 && str[i] != 0)
    i = i + 1;
  if (str[i] == 0)
    return (0);
  while (str[i] != 0)
    if (is_separator(str[i++], separators) == 0)
      {
	nb = nb + 1;
	if (flag == 0 && is_separator(str[i], separators) == 0)
	  return (-1);
	while (flag == 1 && is_separator(str[i], separators) == 0
	       && str[i] != 0)
	  i = i + 1;
      }
  if (is_separator(str[i - 1], separators) == 0)
    nb = nb - 1;
  return (nb);
}

static int	my_wordlen(char *str, int pos, char *separators)
{
  int		len;

  len = 0;
  while (str[pos] != 0 && is_separator(str[pos], separators) != 0)
    {
      len = len + 1;
      pos = pos + 1;
    }
  return (len);
}

static char	*cpy_wd(char *str, int *pos, char *separators)
{
  int		i;
  char		*word;

  if ((word = my_malloc(my_wordlen(str, *pos, separators) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[*pos] != 0 && is_separator(str[*pos], separators) != 0)
    {
      word[i++] = str[*pos];
      *pos = *pos + 1;
    }
  word[i] = 0;
  if (str[*pos] != 0)
    *pos = *pos + 1;
  return (word);
}

char		**my_str_to_wordtab(char *str, char *separators,
				    const int flag)
{
  char		**tab;
  int		nb_wd;
  int		i;
  int		j;

  if ((nb_wd = find_nb_wd(str, separators, flag)) <= 0
      || (tab = my_malloc((nb_wd + 1) * sizeof(char *))) == NULL)
    return (NULL);
  i = -1;
  j = 0;
  while (++i < nb_wd)
    {
      while (flag == 1 && str[j] != 0 && is_separator(str[j], separators) == 0)
	j = j + 1;
      if ((tab[i] = cpy_wd(str, &j, separators)) == NULL)
	return (NULL);
    }
  tab[i] = NULL;
  return (tab);
}
