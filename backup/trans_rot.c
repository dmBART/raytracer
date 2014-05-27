/*
** trans_rot.c for trans_rot in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Wed Mar 12 08:48:31 2014 Thibault Woivre
** Last update Wed Mar 12 08:50:09 2014 Thibault Woivre
*/

#include	"mlxwin.h"

int		rotate_x(t_pos *xyz, double angle)
{
  double	y;
  double	z;

  y = xyz->y;
  z = xyz->z;
  xyz->y = cos(angle) * y - sin(angle) * z;
  xyz->z = sin(angle) * y + cos(angle) * z;
  return (0);
}

int		rotate_y(t_pos *xyz, double angle)
{
  double	x;
  double	z;

  x = xyz->x;
  z = xyz->z;
  xyz->x = cos(angle) * x + sin(angle) * z;
  xyz->z = cos(angle) * z - sin(angle) * x;
  return (0);
}

int		rotate_z(t_pos *xyz, double angle)
{
  double	x;
  double	y;

  x = xyz->x;
  y = xyz->y;
  xyz->x = cos(angle) * x - sin(angle) * y;
  xyz->y = sin(angle) * x + cos(angle) * y;
  return (0);
}

int		translation_xyz(t_win *mlxwin, t_pos translation)
{
  mlxwin->p_oeil.x -= translation.x;
  mlxwin->p_oeil.y -= translation.y;
  mlxwin->p_oeil.z -= translation.z;
  return (0);
}
