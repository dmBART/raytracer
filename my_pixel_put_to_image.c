/*
** my_pixel_put_to_image.c for my_pixel_put_to_image in /home/woivre_t/tp_epitech/igraph/tp2_igraph
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Thu Nov  7 11:00:47 2013 Thibault Woivre
** Last update Sun Mar 16 20:36:55 2014 Thibault Woivre
*/

#include	"mlxwin.h"

int		my_pixel_put_to_image(int x, int y, unsigned long color,
				      t_win *mlxwin)
{
  int		bpp;
  char		*data;
  int		sl;
  int		endian;

  data = mlx_get_data_addr(mlxwin->img, &bpp, &sl, &endian);
  data[y * sl + x * bpp / 8] = (color & 0xFF);
  data[y * sl + x * bpp / 8 + 1] = (color & 0xFF00) >> 8;
  data[y * sl + x * bpp / 8 + 2] = (color & 0xFF0000) >> 16;
  return (0);
}
