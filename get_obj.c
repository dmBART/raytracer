/*
** get_obj.c for get_obj in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
**
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
**
** Started on  Wed Mar 12 08:46:23 2014 Thibault Woivre
** Last update Mon May 26 12:02:44 2014 dylan manin
*/

#include	"mlxwin.h"

t_obj		*get_obj(char *file_name)
{
  int		i;
  t_obj		*tab_obj;
  int		fd;
  char		*s;
  char		**tab;

  i = 0;
  tab_obj = creat_tab_obj(file_name);
  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
      my_putstr("Error during file opening\n");
      exit (1);
    }
  while ((s = get_next_line(fd)) != NULL)
    {
      tab = my_str_to_wordtab(s);
      fill_tab(tab_obj, tab, i);
      free(s);
      i++;
    }
  close(fd);
  return (tab_obj);
}

int		fill_tab(t_obj *tab_obj, char **tab, int i)
{
  if (check_error(tab))
    {
      aff_manuel();
      exit (1);
    }
  (tab_obj[i]).obj = my_getnbr(tab[0]);
  (tab_obj[i]).color = get_color(my_getnbr(tab[3]),
				 my_getnbr(tab[2]), my_getnbr(tab[1]));
  (tab_obj[i].trans.x) = my_getnbr(tab[4]);
  (tab_obj[i].trans.y) = my_getnbr(tab[5]);
  (tab_obj[i].trans.z) = my_getnbr(tab[6]);
  (tab_obj[i].rot.x) = (double) my_getnbr(tab[7]) * M_PI / 180;
  (tab_obj[i].rot.y) = (double) my_getnbr(tab[8]) * M_PI / 180;
  (tab_obj[i].rot.z) = (double) my_getnbr(tab[9]) * M_PI / 180;
  (tab_obj[i].angle) = (double) my_getnbr(tab[10]) * M_PI / 180;
  (tab_obj[i].rayon) = (double) my_getnbr(tab[11]);
  (tab_obj[i].taille) = (double) my_getnbr(tab[12]);
  (tab_obj[i].coef) = (double) my_getnbr(tab[13]) / 100;
  return (0);
}

int		check_error(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL || my_strlen_wordtab(tab) != 14)
    return (1);
  while (i != 14)
    {
      if (!my_str_isnum(tab[i++]))
	return (1);
    }
  if (my_getnbr(tab[0]) < 1 || my_getnbr(tab[0]) > 5)
    return (1);
  if (my_getnbr(tab[1]) < 0 || my_getnbr(tab[1]) > 255)
    return (1);
  if (my_getnbr(tab[2]) < 0 || my_getnbr(tab[1]) > 255)
    return (1);
  if (my_getnbr(tab[3]) < 0 || my_getnbr(tab[3]) > 255)
    return (1);
  if (my_getnbr(tab[13]) < 0 || my_getnbr(tab[13]) > 100)
    return (1);
  return (0);
}

t_obj		*creat_tab_obj(char *file_name)
{
  char		*s;
  t_obj		*tab_obj;
  int		fd;
  int		i;

  i = 0;
  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
      my_putstr("Error during file opening\n");
      exit (1);
    }
  while ((s = get_next_line(fd)) !=  NULL)
    {
      free(s);
      i++;
    }
  tab_obj = xmalloc(sizeof(*tab_obj) * (i + 1));
  tab_obj[i].obj = 0;
  close(fd);
  return (tab_obj);
}

int		get_color(int r, int g, int b)
{
  int		color;

  color = 0;
  color = (color + r) << 8;
  color = (color + g) << 8;
  color = (color + b);
  return (color);
}
