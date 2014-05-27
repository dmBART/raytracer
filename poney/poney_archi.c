/*
** poney_archi.c for poney in /home/vincen_o/rendu/Igraph/RT
**
** Made by arthur vincent
** Login   <vincen_o@epitech.net>
**
** Started on  Mon May 26 15:29:54 2014 arthur vincent
** Last update Mon May 26 17:34:08 2014 arthur vincent
*/

#include	"poney.h"

void		aff_poney2(t_win *mlxwin, int x, int y)
{
  lign11(mlxwin, x, y + 10);
  lign12(mlxwin, x, y + 11);
  lign13(mlxwin, x, y + 12);
  lign14(mlxwin, x, y + 13);
  lign15(mlxwin, x, y + 14);
  lign16(mlxwin, x, y + 15);
  lign17(mlxwin, x, y + 16);
  lign18(mlxwin, x, y + 17);
  lign19(mlxwin, x, y + 18);
  lign20(mlxwin, x, y + 19);
  lign21(mlxwin, x, y + 20);
  lign22(mlxwin, x, y + 21);
  lign23(mlxwin, x, y + 22);
  lign24(mlxwin, x, y + 23);
  lign25(mlxwin, x, y + 24);
  lign26(mlxwin, x, y + 25);
  lign27(mlxwin, x, y + 25);
  lign28(mlxwin, x, y + 26);
}

void		aff_poney(int x, int y, t_win *mlxwin)
{
  lign02(mlxwin, x, y - 3);
  lign01(mlxwin, x, y - 2);
  lign0(mlxwin, x, y - 1);
  lign1(mlxwin, x, y);
  lign2(mlxwin, x, y + 1);
  lign3(mlxwin, x, y + 2);
  lign4(mlxwin, x, y + 3);
  lign5(mlxwin, x, y + 4);
  lign6(mlxwin, x, y + 5);
  lign7(mlxwin, x, y + 6);
  lign8(mlxwin, x, y + 7);
  lign9(mlxwin, x, y + 8);
  lign10(mlxwin, x, y + 9);
  aff_poney2(mlxwin, x, y);
}

void		lign02(t_win *mlxwin, int x, int y)
{
  aff_line_h(&x, y, 33, mlxwin, BLACK);
  aff_line_h(&x, y, 2, mlxwin, BLUEF);
}
