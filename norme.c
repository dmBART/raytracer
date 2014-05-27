/*
** norme.c for raytracer in /home/manin_d/rendu/raytracer/RT
**
** Made by dylan manin
** Login   <manin_d@epitech.net>
**
** Started on  Fri May 23 14:11:42 2014 dylan manin
** Last update Mon May 26 16:04:33 2014 dylan manin
*/

#include	"mlxwin.h"

int		normal_sphere(t_pos *norm, t_pos xyz, t_win mw)
{
  norm->x = xyz.x;
  norm->y = xyz.y;
  norm->z = xyz.z;
}

int		normal_plan(t_pos *norm, t_pos xyz, t_win mw)
{
  norm->x = 0;
  norm->y = 0;
  norm->z = xyz.z;
}

int		normal_cone(t_pos *norm, t_pos xyz, t_win mw)
{
  norm->x = xyz.x;
  norm->y = xyz.y;
  norm->z = xyz.z * -1;
}

int		normal_cylindre(t_pos *norm, t_pos xyz, t_win mw)
{
  norm->x = xyz.x;
  norm->y = xyz.y;
  norm->z = 0;
}
