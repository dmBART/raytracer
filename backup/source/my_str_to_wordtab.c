/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/woivre_t/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Fri Oct 11 06:30:14 2013 Thibault Woivre
** Last update Thu Mar 13 15:07:11 2014 Thibault Woivre
*/

#include	"../mlxwin.h"

char		**my_str_to_wordtab(char *str)
{
  int		i;
  int		j;
  int		size;
  char		**tab;

  i = 0;
  j = 0;
  tab = xmalloc(8 * my_count_word(str) + 8);
  while (str[j] != 0)
    {
      while (str[j] == ' ')
	j++;
      if (str[j] != 0)
	{
	  tab[i] = xmalloc(my_get_size_wt(str, j) + 1);
	  my_strncpy(tab[i], &str[j], my_get_size_wt(str, j));
	  j = j + my_get_size_wt(str, j);
	  i++;
	}
    }
  tab[i] = NULL;
  return (tab);
}

int		my_get_size_wt(char *str, int j)
{
  int		i;

  i = 0;
  while (str[j + i] != 0 && str[j + i] != ' ')
    i++;
  return (i);
}

int		my_count_word(char *str)
{
  int		i;
  int		size;

  i = 0;
  size = 0;
  if (str == NULL)
    exit (1);
  while (str[i] != 0)
    {
      if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
	size++;
      i++;
    }
  return (size);
}
