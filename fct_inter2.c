/*
** fct_inter2.c for fct_inter2 in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
**
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
**
** Started on  Fri Mar 14 11:42:12 2014 Thibault Woivre
** Last update Mon May 26 16:33:15 2014 dylan manin
*/

#include	"mlxwin.h"

double		inter_plan2(t_pos xyz, double z)
{
  double	k;

  if (abs(xyz.z) <= 0.00001)
    return (-1);
  k = (z * (-1)) / xyz.z;
  if (abs(k) >= 0.00001)
    return (k);
  else
    return (-1);
}

int		rotate_trans(t_pos *xyz, t_win *mw, int i)
{
  translation_xyz(mw, mw->tab_obj[i].trans);
  rotate_z(xyz, -mw->tab_obj[i].rot.z);
  rotate_y(xyz, -mw->tab_obj[i].rot.y);
  rotate_x(xyz, -mw->tab_obj[i].rot.x);
  rotate_z(&mw->p_oeil, -mw->tab_obj[i].rot.z);
  rotate_y(&mw->p_oeil, -mw->tab_obj[i].rot.y);
  rotate_x(&mw->p_oeil, -mw->tab_obj[i].rot.x);
  return (0);
}
