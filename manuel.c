/*
** manuel.c for manuel in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Wed Mar 12 08:46:09 2014 Thibault Woivre
** Last update Sun Mar 16 20:51:42 2014 Thibault Woivre
*/

#include	"mlxwin.h"

int		aff_manuel()
{
  my_putstr("You failed the test Sir !\n");
  return (0);
}

int             gere_key(int keycode, void *param)
{
  if (keycode == 65307)
    exit (1);
  return (0);
}
