/*
** fct_inter.c for fct_inter in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
**
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
**
** Started on  Wed Mar 12 08:45:57 2014 Thibault Woivre
** Last update Wed May 21 15:55:14 2014 dylan manin
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

double		inter_cone(t_pos xyz, t_win mw, int i, double *cos)
{
  double	var[8];

  rotate_trans(&xyz, &mw, i);
  mw.p_oeil.z -= mw.tab_obj[i].taille;
  var[0] = tan(mw.tab_obj[i].angle);
  var[3] = xyz.x * xyz.x + xyz.y * xyz.y - var[0] * var[0] * xyz.z * xyz.z;
  var[4] = 2 * (mw.p_oeil.x * xyz.x + mw.p_oeil.y *
                xyz.y - var[0] * var[0] * mw.p_oeil.z * xyz.z);
  var[5] = mw.p_oeil.x * mw.p_oeil.x + mw.p_oeil.y * mw.p_oeil.y
    - mw.p_oeil.z * mw.p_oeil.z * var[0] * var[0];
  var[2] = var[4] * var[4] - 4.0 * var[3] * var[5];
  var[6] = (-var[4] + sqrt(var[2])) / (2 * var[3]);
  var[7] = (-var[4] - sqrt(var[2])) / (2 * var[3]);
  var[1] = min_pos(var[6], var[7]);
  if (var[2] >= 0 && (mw.p_oeil.z + var[1] * xyz.z < 0.00001 && mw.p_oeil.z +
		      var[1] * xyz.z > -mw.tab_obj[i].taille))
    {
      //*cos = (mw.p_oeil.x + var[1] * xyz.x) * xyz.x + (mw.p_oeil.y + var[1] *
      //						       xyz.y) * xyz.y - (mw.p_oeil.z + var[1] * xyz.z) * var[0];
      return (var[1]);
    }
  mw.tab_obj[i].rayon = mw.tab_obj[i].taille / tan(mw.tab_obj[i].angle);
//*cos = (mw.p_oeil.x + var[1] * xyz.x) * xyz.x + (mw.p_oeil.y + var[1] *
//						   xyz.y) * xyz.y;
  return (inter_disque(xyz, mw, mw.tab_obj[i].taille, i));
}

double		inter_cylindre(t_pos xyz, t_win mw, int i)
{
  double	var[9];

  rotate_trans(&xyz, &mw, i);
  var[2] = xyz.x * xyz.x + xyz.y * xyz.y;
  var[3] = 2.0 * (mw.p_oeil.x * xyz.x + mw.p_oeil.y * xyz.y);
  var[4] = mw.p_oeil.x * mw.p_oeil.x + mw.p_oeil.y * mw.p_oeil.y -
    mw.tab_obj[i].rayon * mw.tab_obj[i].rayon;
  var[1] = var[3] * var[3] - 4.0 * var[2] * var[4];
  var[5] = (-var[3] + sqrt(var[1])) / (2 * var[2]);
  var[6] = (-var[3] - sqrt(var[1])) / (2 * var[2]);
  var[0] = min_pos(var[5], var[6]);
  if (var[1] >= 0 && (mw.p_oeil.z + var[0] * xyz.z > 0.00001 && mw.p_oeil.z +
		      var[0] * xyz.z < mw.tab_obj[i].taille))
    {
      //*cos = (mw.p_oeil.x + var[1] * xyz.x) * xyz.x + (mw.p_oeil.y + var[1] *
      //						       xyz.y) * xyz.y;
      return (var[0]);
    }
  var[7] = inter_disque(xyz, mw, - mw.tab_obj[i].taille, i);
  var[8] = inter_disque(xyz, mw, 0, i);
//*cos = (mw.p_oeil.x + var[1] * xyz.x) * xyz.x + (mw.p_oeil.y + var[1] *
//						       xyz.y) * xyz.y;
  return (min_pos(var[7], var[8]));
}
