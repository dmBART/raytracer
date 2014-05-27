/*
** cylindre.c for rtv1 in /home/vincen_o/rendu/Igraph/MUL_2013_rtv1
**
** Made by Arthur Vincent
** Login   <vincen_o@epitech.net>
**
** Started on  Thu Mar 13 18:12:22 2014 Arthur Vincent
** Last update Thu May 22 16:33:04 2014 bayle_q
*/

#include	"header.h"

void		calcul_cylindre(t_un *fou, t_var *cyn, int size)
{
  cyn->x = fou->oex - fou->sx;
  cyn->y = fou->oey - fou->sy;
  cyn->z = fou->oez - fou->sz;
  cyn->vx = fou->vx - fou->sx;
  cyn->vy = fou->vy - fou->sy;
  cyn->vz = fou->vz - fou->sz;
  rotate_x(&cyn->vy, &cyn->vz, fou->anglex);
  rotate_x(&cyn->y, &cyn->z, fou->anglex);
  rotate_y(&cyn->z, &cyn->x, fou->angley);
  rotate_y(&cyn->vz, &cyn->vx, fou->angley);
  rotate_z(&cyn->x, &cyn->y, fou->anglez);
  rotate_z(&cyn->vx, &cyn->vy, fou->anglez);
  cyn->a = (cyn->vx * cyn->vx) + (cyn->vy * cyn->vy);
  cyn->b = 2 * cyn->x * cyn->vx + 2 * cyn->y * cyn->vy;
  cyn->c = (cyn->x * cyn->x) + (cyn->y * cyn->y) - (size * size);
  cyn->delta = (cyn->b * cyn->b) - (4 * cyn->a * cyn->c);
  cyn->k1 = (- cyn->b + sqrt(cyn->delta)) / (2 * cyn->a);
  cyn->k2 = (- cyn->b - sqrt(cyn->delta)) / (2 * cyn->a);
}

void		calc_koef_cyl(t_un *fou, t_var *cyn, int size)
{
  calcul_cylindre(fou, cyn, size);
  if (cyn->k1 > cyn->k2)
    {
      cyn->z1 = cyn->z + cyn->k2 * cyn->vz;
      cyn->z2 = cyn->z + cyn->k1 * cyn->vz;
      fou->k = cyn->k2;
    }
  else
    {
      cyn->z1 = cyn->z + cyn->k1 * cyn->vz;
      cyn->z2 = cyn->z + cyn->k2 * cyn->vz;
      fou->k = cyn->k1;
    }
}

void		calc_disc_cyl(t_disc *calc, t_var *cyn, int len)
{
  calc->k1 = - (cyn->z + (len / 2)) / cyn->vz;
  calc->z1 = cyn->z + calc->k1 * cyn->vz;
  calc->x1 = cyn->x + calc->k1 * cyn->vx;
  calc->y1 = cyn->y + calc->k1 * cyn->vy;
  calc->k2 = - (cyn->z + (- len / 2)) / cyn->vz;
  calc->z2 = cyn->z + calc->k2 * cyn->vz;
  calc->x2 = cyn->x + calc->k2 * cyn->vx;
  calc->y2 = cyn->y + calc->k2 * cyn->vy;
}

int		inter_cylindre(t_un *fou, int size, int len)
{
  t_disc	calc;
  t_var		cyn;

  calc_koef_cyl(fou, &cyn, size);
  calc_disc_cyl(&calc, &cyn, len);
  if ((calc.x1 * calc.x1) + (calc.y1 * calc.y1) <= (size * size))
    {
      fou->k = calc.k1;
      return (1);
    }
  if ((calc.x2 * calc.x2) + (calc.y2 * calc.y2) <= (size * size))
    {
      fou->k = calc.k2;
      return (1);
    }
  if ((cyn.z1 < - len / 2 || cyn.z1 > len / 2) &&
      (cyn.z2 < - len / 2 || cyn.z2 > len / 2))
    return (0);
  if (cyn.delta > 0)
    return (1);
  else
    return (0);
}
