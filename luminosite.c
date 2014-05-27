/*
** luminosite.c for raytracer in /home/manin_d/rendu/raytracer/RT
**
** Made by dylan manin
** Login   <manin_d@epitech.net>
**
** Started on  Fri May 23 11:56:15 2014 dylan manin
** Last update Tue May 27 13:08:43 2014 dylan manin
*/

#include	"mlxwin.h"

double		scalaire(t_pos xyz, t_pos norm)
{
  double	n;
  double	l;
  double	cos;

  n = sqrt(norm.x * norm.x + norm.y * norm.y + norm.z * norm.z);
  l = sqrt(xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z);
  cos = norm.x * xyz.x + norm.y * xyz.y + norm.z * xyz.z;
  return (cos / (n * l));
}

int		bright(int *var, double cos)
{
  double        r;
  double        g;
  double        b;
  int		color;

  color = var[1];
  r = color & 0xFF;
  g = (color & 0xFF00) >> 8;
  b = (color & 0xFF0000) >> 16;
  if (var[2] == 2)
    {
      r =  r * (cos);
      g =  g * (cos);
      b =  b * (cos);
    }
  else
    {
      r =  r * (1 - cos);
      g =  g * (1 - cos);
      b =  b * (1 - cos);
    }
  r < 0.0001 ? r = 0.0 : 0;
  g < 0.0001 ? g = 0.0 : 0;
  b < 0.0001 ? b = 0.0 : 0;
  return (get_color((int) r, (int) g, (int)b));

}


int		luminosite(t_pos xyz, double k, t_win mw, int *var)
{
  int		x;
  int		j;
  t_pos		norm;
  double	a;
  double	cos;

  j = 0;
  x = 0;

  var[2] == 1 ? normal_sphere(&norm, xyz, mw) : 0;
  var[2] == 2 ? normal_plan(&norm, xyz, mw) : 0;
  var[2] == 3 ? normal_cone(&norm, xyz, mw) : 0;
  var[2] == 4 ? normal_cylindre(&norm, xyz, mw) : 0;
  //rotate_trans(&norm, &mw, var[2]);
  xyz.x = mw.p_oeil.x + k * xyz.x - mw.tab_lum[0].xyz.x;
  xyz.y = mw.p_oeil.y + k * xyz.y - mw.tab_lum[0].xyz.y;
  xyz.z = mw.p_oeil.z + k * xyz.z - mw.tab_lum[0].xyz.z;
  //  xyz.x = xyz.x - mw.tab_lum[0].xyz.x;
  //xyz.y = xyz.y - mw.tab_lum[0].xyz.y;
  //xyz.z = xyz.z - mw.tab_lum[0].xyz.z;
  cos = scalaire(xyz, norm);
  if (cos < 0.00001)
    cos = 0.0;
  if (cos > 0.99999)
    cos = 1.0;
  //  if (cos > 0.00001 && cos < 0.99999)
  //printf("%.3f\n", cos);
  return (bright(var, cos));
}

/*

autre effet style
*/

/*
int		luminosite(t_pos xyz, double k, t_win mw, int *var)
{
  int		x;
  int		j;
  t_pos		norm;
  double	a;
  double	cos;

  j = 0;
  x = 0;

  var[2] == 1 ? normal_sphere(&norm, xyz, mw) : 0;
  var[2] == 2 ? normal_plan(&norm, xyz, mw) : 0;
  var[2] == 3 ? normal_cone(&norm, xyz, mw) : 0;
  var[2] == 4 ? normal_cylindre(&norm, xyz, mw) : 0;
    xyz.x = mw.p_oeil.x + k * xyz.x - mw.tab_lum[0].xyz.x;
xyz.y = mw.p_oeil.y + k * xyz.y - mw.tab_lum[0].xyz.y;
xyz.z = mw.p_oeil.z + k * xyz.z - mw.tab_lum[0].xyz.z;
  rotate_trans(&norm, &mw, var[2]);
  cos = scalaire(xyz, norm);
  cos *= M_PI / 180;
  if (cos < 0.00001)
    return (0);
  else
    {
      //  printf("%.3f\n", cos);
    return (bright(var[1], cos));
    }
  return (0);
}

*/
/*

effet trop drole
*/

/*
int		luminosite(t_pos xyz, double k, t_win mw, int *var)
{
  int		x;
  int		j;
  t_pos		norm;
  double	a;
  double	cos;

  j = 0;
  x = 0;
  //  xyz.x = mw.p_oeil.x + k * xyz.x - mw.tab_lum[0].xyz.x;
  //xyz.y = mw.p_oeil.y + k * xyz.y - mw.tab_lum[0].xyz.y;
  //xyz.z = mw.p_oeil.z + k * xyz.z - mw.tab_lum[0].xyz.z;
  var[2] == 1 ? normal_sphere(&norm, xyz) : 0;
  var[2] == 2 ? normal_plan(&norm, xyz) : 0;
  var[2] == 3 ? normal_cone(&norm, xyz) : 0;
  var[2] == 4 ? normal_cylindre(&norm, xyz) : 0;
    rotate_trans(&norm, &mw, var[2]);
    xyz.x = xyz.x - mw.tab_lum[0].xyz.x; // vecteur N
  xyz.y = xyz.y - mw.tab_lum[0].xyz.y;
  xyz.z = xyz.z - mw.tab_lum[0].xyz.z;
  cos = scalaire(xyz, norm);
  if (cos < 0.00001)
    return (0);
  else
    return (bright(var[1], cos));
  return (0);
}

*/
