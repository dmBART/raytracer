/*
** ombre.c for put_ombre in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
**
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
**
** Started on  Sun Mar 16 14:31:58 2014 Thibault Woivre
** Last update Tue May 27 13:19:19 2014 dylan manin
*/

#include	"mlxwin.h"

int		change_color(int *var, t_pos xyz, t_win mw, double k)
{
  int		i;
  int		x;
  int		lum;
  int		color;

  i = 0;
  x = 0;
  color = var[1];
  while (mw.tab_lum[i].end != 1)
    {
      x += put_shadow(xyz, k, mw, i);
      i++;
    }
    color = luminosite(xyz, k, mw, var);
  if (x > 0)
    {
      if (x == 1 & var[2] != 2)
	return (0);
      else
	color = darken(color, x);
    }
  return (color);
}

int		darken(int color, int x)
{
  double	r;
  double	g;
  double	b;

  r = color & 0xFF;
  g = (color & 0xFF00) >> 8;
  b = (color & 0xFF0000) >> 16;
  r =  r * (100.0 - (double)x * 20.0) / 100.0;
  g =  g * (100.0 - (double)x * 20.0) / 100.0;
  b =  b * (100.0 - (double)x * 20.0) / 100.0;
  r < 0.0001 ? r = 0.0 : 0;
  g < 0.0001 ? g = 0.0 : 0;
  b < 0.0001 ? b = 0.0 : 0;
  return (get_color((int) b, (int) g, (int)r));
}

int		put_shadow(t_pos xyz, double k, t_win mw, int i)
{
  int		x;
  int		j;
  double	a;
  double	cos;

  j = 0;
  x = 0;
  xyz.x = mw.p_oeil.x + k * xyz.x - mw.tab_lum[i].xyz.x;
  xyz.y = mw.p_oeil.y + k * xyz.y - mw.tab_lum[i].xyz.y;
  xyz.z = mw.p_oeil.z + k * xyz.z - mw.tab_lum[i].xyz.z;
  mw.p_oeil.x = mw.tab_lum[i].xyz.x;
  mw.p_oeil.y = mw.tab_lum[i].xyz.y;
  mw.p_oeil.z = mw.tab_lum[i].xyz.z;
  while (mw.tab_obj[j].obj != 0)
    {
      mw.tab_obj[j].obj == 1 ? a = inter_sphere(xyz, mw, j) : 0;
      mw.tab_obj[j].obj == 2 ? a = inter_plan(xyz, mw, j) : 0;
      if (mw.tab_obj[j].obj == 2 &&
	  mw.tab_obj[j].trans.z > mw.tab_lum[i].xyz.z)
	return (1);
      mw.tab_obj[j].obj == 3 ? a = inter_cone(xyz, mw, j, &cos) : 0;
      mw.tab_obj[j].obj == 4 ? a = inter_cylindre(xyz, mw, j) : 0;
      a > 0.00001 && a < 0.99999 ? x++ : 0;
      j++;
    }
  return (x);
}
