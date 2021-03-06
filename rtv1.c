/*
** wolf3d.c for wolf3d in /home/woivre_t/rendu/MUL_2013_wolf3d
**
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
**
** Started on  Sun Dec 22 13:37:13 2013 Thibault Woivre
** Last update Tue May 27 18:01:13 2014 arthur vincent
*/

#include	"mlxwin.h"

int		main(int ac, char **av)
{
  t_lum		*tab_lum;
  t_pos		test;
  t_win		mlxwin;

  ac != 4 ? exit (1) : 0;
  (mlxwin.mlx = mlx_init()) == NULL ? exit (1) : 0;
  (mlxwin.win = mlx_new_window(mlxwin.mlx, 1000, 1000, "RTV1")) == NULL ?\
    exit (1) : 0;
  (mlxwin.img = mlx_new_image(mlxwin.mlx, 1000, 1000)) == NULL ? exit (1) : 0;
  (mlxwin.img_wait = mlx_new_image(mlxwin.mlx, 1000, 1000)) == NULL ?
    exit (1) : 0;
  get_eye(&mlxwin, av[1]);
  mlxwin.tab_obj = get_obj(av[2]);
  mlxwin.tab_lum = get_lum(av[3]);
  remplis_image(&mlxwin);
  mlx_key_hook(mlxwin.win, gere_key, &mlxwin);
  mlx_expose_hook(mlxwin.win, gere_expose, &mlxwin);
  mlx_loop(mlxwin.mlx);
  return (0);
}

int		remplis_image(t_win *mlxwin)
{
  int		x;
  int		y;
  int		i;

  y = 0;
  i = 0;
  aff_wait_bar(x, y, 999, mlxwin);
  while (y < 1000)
    {
      x = 0;
      while (x < 1000)
	{
	  my_pixel_put_to_image(x, y, calc(x, y, mlxwin), mlxwin);
	  aff_wait_bar(x, y, 999, mlxwin);
	  x++;
	}
      y++;
    }
  return (0);
}

int		gere_expose(void *param)
{
  mlx_put_image_to_window((*(t_win*)param).mlx, (*(t_win*)param).win, \
  			  (*(t_win*)param).img, 0, 0);
  return (0);
}

int		calc(int x, int y, t_win *mlxwin)
{
  int		n;
  t_pos		xyz;

  xyz.x = 100;
  xyz.y = 500 - x;
  xyz.z = 500 - y;
  rotate_x(&xyz, mlxwin->r_oeil.x);
  rotate_y(&xyz, mlxwin->r_oeil.y);
  rotate_z(&xyz, mlxwin->r_oeil.z);
  return (get_pixel_color(xyz, mlxwin));
}

int		get_pixel_color(t_pos xyz, t_win *mw)
{
  double	k;
  double	a;
  double	cos;
  int		vr[3];

  vr[0] = 0;
  k = 1000000;
  vr[1] = 0x000000;
  while (mw->tab_obj[vr[0]].obj != 0)
    {
      mw->tab_obj[vr[0]].obj == 1 ? a = inter_sphere(xyz, *mw, vr[0]) : 0;
      mw->tab_obj[vr[0]].obj == 2 ? a = inter_plan(xyz, *mw, vr[0]) : 0;
      mw->tab_obj[vr[0]].obj == 3 ? a = inter_cone(xyz, *mw, vr[0], &cos) : 0;
      mw->tab_obj[vr[0]].obj == 4 ? a = inter_cylindre(xyz, *mw, vr[0]) : 0;
      if (a < k && a > 0.000001)
	{
	  k = a;
	  vr[1] = mw->tab_obj[vr[0]].color;
	  vr[2] = mw->tab_obj[vr[0]].obj;
	}
      vr[0] = vr[0] + 1;
    }
  vr[1] = change_color(vr, xyz, *mw, k);
  return (vr[1]);
}
