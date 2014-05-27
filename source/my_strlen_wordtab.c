/*
** my_strlen_wordtab.c for my_strlen_wordtab in /home/woivre_t/rendu/PSU_2013_minishell1/source
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Tue Dec 17 11:34:13 2013 Thibault Woivre
** Last update Thu Mar 13 15:48:19 2014 Thibault Woivre
*/

#include	"../mlxwin.h"

int		my_strlen_wordtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
