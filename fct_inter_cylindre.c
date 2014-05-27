/*
** fct_inter_cylindre.c for raytracer in /home/bayle_q/Perso/RT
**
** Made by bayle_q
** Login   <bayle_q@epitech.net>
**
** Started on  Thu May 22 16:49:58 2014 bayle_q
** Last update Fri May 23 10:53:57 2014 bayle_q
*/

#include	"mlxwin.h"

double		inter_cylindre(t_pos xyz, t_win mw, int i)
{
  double	var[10];
  t_calc	disc;

  calcul_cylindre(var, &xyz, &mw, i);
  inter_disque_cyl(xyz, mw, &disc, i);
  if ((disc.x * disc.x) + (disc.y * disc.y) <= (mw.tab_obj[i].rayon *
						mw.tab_obj[i].rayon))
    return (min_pos(disc.k, var[0]));
  if ((disc.x2 * disc.x2) + (disc.y2 * disc.y2) <= (mw.tab_obj[i].rayon *
						    mw.tab_obj[i].rayon))
    return (min_pos(disc.k2, var[0]));
  if (var[7] < -mw.tab_obj[i].taille / 2 ||
      var[7] > mw.tab_obj[i].taille / 2 &&
      (var[8] < -mw.tab_obj[i].taille / 2 ||
       var[8] > mw.tab_obj[i].taille / 2))
       return (-1);
  if (var[1] >= 0)
    return (var[0]);
}

void		inter_disque_cyl(t_pos xyz, t_win mw, t_calc *disc, int i)
{
  disc->k = - (mw.p_oeil.z + (mw.tab_obj[i].taille / 2)) / xyz.z;
  disc->z = mw.p_oeil.z + disc->k * xyz.z;
  disc->y = mw.p_oeil.y + disc->k * xyz.y;
  disc->x = mw.p_oeil.x + disc->k * xyz.x;
  disc->k2 = - (mw.p_oeil.z + ( - mw.tab_obj[i].taille / 2)) / xyz.z;
  disc->z2 = mw.p_oeil.z + disc->k2 * xyz.z;
  disc->y2 = mw.p_oeil.y + disc->k2 * xyz.y;
  disc->x2 = mw.p_oeil.x + disc->k2 * xyz.x;
}

void		calcul_cylindre(double *var, t_pos *xyz, t_win *mw, int i)
{
  rotate_trans(xyz, mw, i);
  var[2] = xyz->x * xyz->x + xyz->y * xyz->y;
  var[3] = 2.0 * (mw->p_oeil.x * xyz->x + mw->p_oeil.y * xyz->y);
  var[4] = mw->p_oeil.x * mw->p_oeil.x + mw->p_oeil.y * mw->p_oeil.y -
    mw->tab_obj[i].rayon * mw->tab_obj[i].rayon;
  var[1] = var[3] * var[3] - 4.0 * var[2] * var[4];
  var[5] = (-var[3] + sqrt(var[1])) / (2 * var[2]);
  var[6] = (-var[3] - sqrt(var[1])) / (2 * var[2]);
  var[0] = min_pos(var[5], var[6]);
  if (var[5] > var[6])
    {
      var[7] = mw->p_oeil.z + var[6] * xyz->z;
      var[8] = mw->p_oeil.z + var[5] * xyz->z;
    }
  else
    {
      var[7] = mw->p_oeil.z + var[5] * xyz->z;
      var[8] = mw->p_oeil.z + var[6] * xyz->z;
    }
}
