/*
** fct_inter.c for fct_inter in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
**
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
**
** Started on  Wed Mar 12 08:45:57 2014 Thibault Woivre
** Last update Tue May 27 12:59:05 2014 dylan manin
*/

#include	"mlxwin.h"

double		inter_sphere(t_pos xyz, t_win mw, int i)
{
  double	k;
  double	delta;
  double	a;
  double	b;
  double	c;
  double	racine1;
  double	racine2;

  translation_xyz(&mw, mw.tab_obj[i].trans);
  a = xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z;
  b = 2.0 * (mw.p_oeil.x * xyz.x + mw.p_oeil.y * xyz.y + mw.p_oeil.z * xyz.z);
  c = (mw.p_oeil.x * mw.p_oeil.x + mw.p_oeil.y * mw.p_oeil.y + mw.p_oeil.z *
       mw.p_oeil.z - mw.tab_obj[i].rayon * mw.tab_obj[i].rayon);
  delta = b * b - 4.0 * a * c;
  racine1 = (-b + sqrt(delta)) / (2 * a);
  racine2 = (-b - sqrt(delta)) / (2 * a);
  if (delta >= 0)
    {
      k = min_pos(racine1, racine2);
      return (k);
    }
  return (-1);
}

double		min_pos(double a, double b)
{
  if (a >= b && a > 0.00001 && b > 0.00001)
    return (b);
  else if (b > a && a > 0.00001 && b > 0.00001)
    return (a);
  else if (a > 0.00001)
    return (a);
  else if (b > 0.00001)
    return (b);
  return (-1);
}

double		inter_plan(t_pos xyz, t_win mw, int i)
{
  double	k;

  translation_xyz(&mw, mw.tab_obj[i].trans);
  rotate_z(&xyz, -mw.tab_obj[i].rot.z);
  rotate_y(&xyz, -mw.tab_obj[i].rot.y);
  rotate_x(&xyz, -mw.tab_obj[i].rot.x);
  rotate_z(&mw.p_oeil, -mw.tab_obj[i].rot.z);
  rotate_y(&mw.p_oeil, -mw.tab_obj[i].rot.y);
  rotate_x(&mw.p_oeil, -mw.tab_obj[i].rot.x);
  if (abs(xyz.z) < 0.00001)
    return (-1);
  k = -(mw.p_oeil.z/xyz.z);
  if (abs(k) >= 0)
    return (k);
  else
    return (0);
}
