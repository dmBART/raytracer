/*
** xmalloc.c for xmalloc in /home/woivre_t/rendu/lib
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Mon Nov 25 02:34:55 2013 Thibault Woivre
** Last update Mon Nov 25 04:04:07 2013 Thibault Woivre
*/

#include	<stdlib.h>
#include	<stdio.h>

void		*xmalloc(int size)
{
  void		*str;

  str = malloc(size);
  if (str == NULL)
    {
      my_putstr("Problem during the memory allocation\n");
      exit (1);
    }
  return (str);
}
