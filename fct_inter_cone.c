/*
** fct_inter_cone.c for raytracer in /home/bayle_q/Perso/RT
**
** Made by bayle_q
** Login   <bayle_q@epitech.net>
**
** Started on  Fri May 23 09:37:39 2014 bayle_q
** Last update Fri May 23 11:17:51 2014 bayle_q
*/

#include	"mlxwin.h"

void		calcul_cone(double *var, t_pos *xyz, t_win *mw, int i)
{
  rotate_trans(xyz, mw, i);
  mw->p_oeil.z -= mw->tab_obj[i].taille;
  var[0] = tan(mw->tab_obj[i].angle);
  var[3] = xyz->x * xyz->x + xyz->y * xyz->y -
    var[0] * var[0] * xyz->z * xyz->z;
  var[4] = 2 * (mw->p_oeil.x * xyz->x + mw->p_oeil.y *
                xyz->y - var[0] * var[0] * mw->p_oeil.z * xyz->z);
  var[5] = mw->p_oeil.x * mw->p_oeil.x + mw->p_oeil.y * mw->p_oeil.y
    - mw->p_oeil.z * mw->p_oeil.z * var[0] * var[0];
  var[2] = var[4] * var[4] - 4.0 * var[3] * var[5];
  var[6] = (-var[4] + sqrt(var[2])) / (2 * var[3]);
  var[7] = (-var[4] - sqrt(var[2])) / (2 * var[3]);
  var[1] = min_pos(var[6], var[7]);
  if (var[6] > var[7] && var[7] > 0)
    {
      var[8] = mw->p_oeil.z + var[7] * xyz->z;
      var[9] = mw->p_oeil.z + var[6] * xyz->z;
    }
  else
    {
      var[8] = mw->p_oeil.z + var[6] * xyz->z;
      var[9] = mw->p_oeil.z + var[7] * xyz->z;
    }
}

double		inter_cone(t_pos xyz, t_win mw, int i, double *cos)
{
  double	var[9];
  t_calc	disc;

  calcul_cone(var, &xyz, &mw, i);
  inter_disque_cone(xyz, mw, &disc, i);
  if ((disc.x * disc.x) + (disc.y * disc.y) <= (mw.tab_obj[i].taille *
						mw.tab_obj[i].taille))
    return (min_pos(disc.k, var[1]));
    if (var[8] < -mw.tab_obj[i].taille ||
	var[8] > 0 &&
	(var[9] < -mw.tab_obj[i].taille ||
	 var[9] > 0))
      return (-1);
  if (var[2] > 0)
    return (var[1]);
}

void		inter_disque_cone(t_pos xyz, t_win mw, t_calc *disc, int i)
{
  disc->k = - (mw.p_oeil.z + (mw.tab_obj[i].taille)) / xyz.z;
  disc->z = mw.p_oeil.z + disc->k * xyz.z;
  disc->y = mw.p_oeil.y + disc->k * xyz.y;
  disc->x = mw.p_oeil.x + disc->k * xyz.x;
}
