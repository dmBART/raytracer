/*
** cone.c for rtv1 in /home/vincen_o/rendu/Igraph/MUL_2013_rtv1
**
** Made by Arthur Vincent
** Login   <vincen_o@epitech.net>
**
** Started on  Thu Mar 13 18:38:22 2014 Arthur Vincent
** Last update Sun Mar 16 20:04:57 2014 Arthur Vincent
*/

#include	"header.h"

void		calcul_cone(t_un *fou, t_var *con)
{
  con->x = fou->oex - fou->sx;
  con->y = fou->oey - fou->sy;
  con->z = fou->oez - fou->sz;
  con->vx = fou->vx - fou->sx;
  con->vy = fou->vy - fou->sy;
  con->vz = fou->vz - fou->sz;
  rotate_x(&con->vy, &con->vz, fou->anglex);
  rotate_x(&con->y, &con->z, fou->anglex);
  rotate_y(&con->z, &con->x, fou->angley);
  rotate_y(&con->vz, &con->vx, fou->angley);
  rotate_z(&con->x, &con->y, fou->anglez);
  rotate_z(&con->vx, &con->vy, fou->anglez);
  con->a = (con->vx * con->vx) + (con->vy * con->vy) -
    (con->vz * con->vz);
  con->b = 2 * ((con->x * con->vx) + (con->y * con->vy) -
		(con->z * con->vz));
  con->c = (con->x * con->x) + (con->y * con->y) -
    (con->z * con->z);
  con->delta = (con->b * con->b) - (4 * con->a * con->c);
  con->k1 = (- con->b + sqrt(con->delta)) / (2 * con->a);
  con->k2 = (- con->b - sqrt(con->delta)) / (2 * con->a);
}

void		calc_koef_con(t_un *fou, t_var *con)
{
  calcul_cone(fou, con);
  if (con->k1 > con->k2 && con->k2 > 0)
    {
      con->z1 = con->z + con->k2 * con->vz;
      con->z2 = con->z + con->k1 * con->vz;
      fou->k = con->k2;
    }
  else
    {
      con->z1 = con->z + con->k1 * con->vz;
      con->z2 = con->z + con->k2 * con->vz;
      fou->k = con->k1;
    }
}

void		calc_disc_con(t_disc *calc, t_var *con, int size)
{
  calc->k1 = - (con->z + size) / con->vz;
  calc->z1 = con->z + calc->k1 * con->vz;
  calc->x1 = con->x + calc->k1 * con->vx;
  calc->y1 = con->y + calc->k1 * con->vy;
}

int		inter_cone(t_un *fou, int size)
{
  t_disc	calc;
  t_var		con;

  calc_koef_con(fou, &con);
  calc_disc_con(&calc, &con, size);
  if ((calc.x1 * calc.x1) + (calc.y1 * calc.y1) <= (size * size))
    {
      fou->k = calc.k1;
      return (1);
    }
  if ((con.z1 < - size || con.z1 > 0) &&
      (con.z2 < - size || con.z2 > 0))
    return (0);
  if (con.delta > 0)
    return (1);
  else
    return (0);
}
