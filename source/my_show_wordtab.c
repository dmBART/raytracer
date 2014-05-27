/*
** my_show_wordtab.c for my_show_wordtab in /home/woivre_t/rendu/Piscine-C-Jour_08/ex_05
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Fri Oct 11 16:41:17 2013 Thibault Woivre
** Last update Sun Mar 16 20:43:12 2014 Thibault Woivre
*/

#include	<stdlib.h>
#include	<stdio.h>

int		my_show_wordtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar(10);
      i++;
    }
  return (0);
}
