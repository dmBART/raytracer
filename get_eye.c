/*
** get_eye.c for get_eye in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Wed Mar 12 08:50:37 2014 Thibault Woivre
** Last update Thu Mar 13 16:08:47 2014 Thibault Woivre
*/

#include	"mlxwin.h"

int		get_eye(t_win *mlxwin, char *file_name)
{
  char		**tab;
  int		fd;
  char		*s;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
      my_putstr("Error during file opening\n");
      exit (1);
    }
  if ((s = get_next_line(fd)) == NULL)
    {
      aff_manuel();
      exit (1);
    }
  tab = my_str_to_wordtab(s);
  fill_eye(tab, mlxwin);
  my_free_wordtab(tab);
  free(s);
  close(fd);
  return (0);
}

int		fill_eye(char **tab, t_win *mlxwin)
{
  if (check_error_eye(tab))
    {
      aff_manuel();
      exit (1);
    }
  (mlxwin->p_oeil).x = my_getnbr(tab[0]);
  (mlxwin->p_oeil).y = my_getnbr(tab[1]);
  (mlxwin->p_oeil).z = my_getnbr(tab[2]);
  (mlxwin->r_oeil).x = (double) my_getnbr(tab[3]) * M_PI / 180;
  (mlxwin->r_oeil).y = (double) my_getnbr(tab[4]) * M_PI / 180;
  (mlxwin->r_oeil).z = (double) my_getnbr(tab[5]) * M_PI / 180;
  rotate_x(&mlxwin->p_oeil, mlxwin->r_oeil.x);
  rotate_y(&mlxwin->p_oeil, mlxwin->r_oeil.y);
  rotate_z(&mlxwin->p_oeil, mlxwin->r_oeil.z);
  return (0);
}

int		check_error_eye(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL || my_strlen_wordtab(tab) != 6)
    return (1);
  while (i != 6)
    {
      if (!my_str_isnum(tab[i++]))
	  return (1);
    }
  return (0);
}
