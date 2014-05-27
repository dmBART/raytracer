/*
** poney.c for poney in /home/vincen_o/rendu/Igraph/RT
**
** Made by arthur vincent
** Login   <vincen_o@epitech.net>
**
** Started on  Sun May 25 22:57:53 2014 arthur vincent
** Last update Mon May 26 15:45:02 2014 arthur vincent
*/

#include	"poney.h"

void		lign1(t_win *mlxwin, int x, int y)
{
  aff_line_h(&x, y, 3, mlxwin, RED);
  aff_line_h(&x, y, 7, mlxwin, BLACK);
  aff_line_h(&x, y, 8, mlxwin, RED);
  aff_line_h(&x, y, 7, mlxwin, BLACK);
  aff_line_h(&x, y, 2, mlxwin, RED);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 3, mlxwin, BLUEC);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 12, mlxwin, ORANGE);
  aff_line_h(&x, y, 3, mlxwin, RED);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
}

void		lign2(t_win *mlxwin, int x, int y)
{
  aff_line_h(&x, y, 29, mlxwin, RED);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, BLUEC);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 3, mlxwin, BLUEC);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, ORANGE);
  aff_line_h(&x, y, 3, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, ORANGE);
  aff_line_h(&x, y, 5, mlxwin, YELLOW);
  aff_line_h(&x, y, 1, mlxwin, ORANGE);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
}

void		lign3(t_win *mlxwin, int x, int y)
{
  aff_line_h(&x, y, 18, mlxwin, RED);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 11, mlxwin, RED);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 1, mlxwin, BLUEC);
  aff_line_h(&x, y, 3, mlxwin, BLUEF);
  aff_line_h(&x, y, 1, mlxwin, ORANGE);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, BLUEC);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 4, mlxwin, YELLOW);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 1, mlxwin, YELLOW);
  aff_line_h(&x, y, 1, mlxwin, RED);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
}

void		lign4(t_win *mlxwin, int x, int y)
{
  aff_line_h(&x, y, 3, mlxwin, ORANGE);
  aff_line_h(&x, y, 7, mlxwin, RED);
  aff_line_h(&x, y, 7, mlxwin, BLUEF);
  aff_line_h(&x, y, 1, mlxwin, RED);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 8, mlxwin, RED);
  aff_line_h(&x, y, 3, mlxwin, BLUEF);
  aff_line_h(&x, y, 3, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 1, mlxwin, BLUEC);
  aff_line_h(&x, y, 3, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, YELLOW);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 4, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 4, mlxwin, YELLOW);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 1, mlxwin, BLUEC);
  aff_line_h(&x, y, 4, mlxwin, BLUEF);
}

void		lign5(t_win *mlxwin, int x, int y)
{
  aff_line_h(&x, y, 8, mlxwin, ORANGE);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 7, mlxwin, BLUEC);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 1, mlxwin, VIOLET);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 5, mlxwin, RED);
  aff_line_h(&x, y, 2, mlxwin, ORANGE);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 1, mlxwin, BLUEC);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 1, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 2, mlxwin, BLUEC);
  aff_line_h(&x, y, 3, mlxwin, BLUEF);
  aff_line_h(&x, y, 3, mlxwin, BLUEC);
  aff_line_h(&x, y, 1, mlxwin, BLUEF);
  aff_line_h(&x, y, 3, mlxwin, YELLOW);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
  aff_line_h(&x, y, 4, mlxwin, BLUEC);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
}
