/*
** get_alum.c for get_alum in /home/woivre_t/rendu/MUL_2013_rtv1/tp/tp1
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Sun Mar 16 11:57:03 2014 Thibault Woivre
** Last update Sun Mar 16 12:46:40 2014 Thibault Woivre
*/

#include	"mlxwin.h"

t_lum		*get_lum(char *file_name)
{
  int		i;
  t_lum		*tab_lum;
  int		fd;
  char		*s;
  char		**tab;

  i = 0;
  tab_lum = creat_tab_lum(file_name);
  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
      my_putstr("Error during file opening\n");
      exit (1);
    }
  while ((s = get_next_line(fd)) != NULL)
    {
      tab = my_str_to_wordtab(s);
      fill_tab_lum(tab_lum, tab, i);
      my_free_wordtab(tab);
      free(s);
      i++;
    }
  close(fd);
  return (tab_lum);
}

t_lum		*creat_tab_lum(char *file_name)
{
  char		*s;
  t_lum		*tab_lum;
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
  tab_lum = xmalloc(sizeof(*tab_lum) * (i + 1));
  tab_lum[i].end = 1;
  close(fd);
  return (tab_lum);
}

int		check_error2(char **tab)
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
  if (my_getnbr(tab[3]) < 0 || my_getnbr(tab[3]) > 255)
    return (1);
  if (my_getnbr(tab[4]) < 0 || my_getnbr(tab[4]) > 255)
    return (1);
  if (my_getnbr(tab[5]) < 0 || my_getnbr(tab[5]) > 255)
    return (1);
  return (0);
}

int		fill_tab_lum(t_lum *tab_lum, char **tab, int i)
{
  if (check_error2(tab))
    {
      aff_manuel();
      exit (1);
    }
  tab_lum[i].xyz.x = my_getnbr(tab[0]);
  tab_lum[i].xyz.y = my_getnbr(tab[1]);
  tab_lum[i].xyz.z = my_getnbr(tab[2]);
  tab_lum[i].color = get_color(my_getnbr(tab[3]),
			       my_getnbr(tab[4]), my_getnbr(tab[5]));
  return (0);
}
