/*
** wait_bar.c for raytracer in /home/vincen_o/rendu/Igraph/RT
**
** Made by arthur vincent
** Login   <vincen_o@epitech.net>
**
** Started on  Sun May 25 20:26:41 2014 arthur vincent
** Last update Tue May 27 17:45:33 2014 arthur vincent
*/

#include	"mlxwin.h"

int		my_pixel_put_to_image_wait(int x, int y, unsigned long color,
				      t_win *mlxwin)
{
  int		bpp;
  char		*data;
  int		sl;
  int		endian;

  data = mlx_get_data_addr(mlxwin->img_wait, &bpp, &sl, &endian);
  data[y * sl + x * bpp / 8] = (color & 0xFF);
  data[y * sl + x * bpp / 8 + 1] = (color & 0xFF00) >> 8;
  data[y * sl + x * bpp / 8 + 2] = (color & 0xFF0000) >> 16;
  return (0);
}

void		aff_line_h(int *x, int y, int len, t_win *mlxwin,
			   unsigned long color)
{
  len = len + *x;
  while (*x < len)
    {
      my_pixel_put_to_image_wait(*x, y, color, mlxwin);
      *x = *x + 1;
    }
}

void		aff_wait_bar(int x, int y, int max_line,t_win *mlxwin)
{
  static int	j = 0;
  int		max;
  int		i;

  max = max_line * max_line;
  i = (x + (y * max_line)) * 350 / max;
  if (j != i)
    {
      j = i;
      aff_poney(300 + i, 400, mlxwin);
      mlx_put_image_to_window(mlxwin->mlx, mlxwin->win, mlxwin->img_wait, 0, 0);
    }
}
