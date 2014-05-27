/*
** tp1_click_pixel.h for my_click_pixel in /home/woivre_t/Tp_epitech/Igraph
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Fri Oct 25 11:49:50 2013 Thibault Woivre
** Last update Sun Mar 16 21:34:27 2014 Thibault Woivre
*/

#ifndef		MLXWIN_H_
# define	MLXWIN_H_

typedef struct	s_pos
{
  double	x;
  double	y;
  double	z;
}		t_pos;

typedef struct	s_obj
{
  int		obj;
  int		color;
  t_pos		trans;
  t_pos		rot;
  double	angle;
  double	rayon;
  double	taille;
  double	coef;
}		t_obj;

typedef struct	s_lum
{
  t_pos		xyz;
  int		color;
  int		end;
}		t_lum;

typedef struct	s_win
{
  void		*mlx;
  void		*win;
  void		*img;
  t_obj		*tab_obj;
  t_lum		*tab_lum;
  t_pos		p_oeil;
  t_pos		r_oeil;
}		t_win;

double		inter_disque(t_pos xyz, t_win mw, double z, int i);
double		inter_plan2(t_pos xyz, double z);
double		inter_sphere(t_pos xyz, t_win mw, int i);
double		inter_cylindre(t_pos xyz, t_win mw, int i);
double		inter_plan(t_pos xyz, t_win mw, int i);
double		min_pos(double a, double b);
int		gere_key(int keycode, void *param);
int		gere_expose(void *param);
t_obj		*get_obj(char *file_name);
t_lum		*get_lum(char *file_name);
int		fill_tab(t_obj *tab_obj,  char **tab, int i);
t_obj		*creat_tab_obj(char *file_name);
int		get_color(int r, int g, int b);
char		*get_next_line(int fd);
char		**my_str_to_wordtab(char *str);
void		*xmalloc(int size);
int		check_error(char **tab);
double		inter_cone(t_pos xyz, t_win mw, int i, double *cos);
t_lum		*creat_tab_lum(char *file_name);
int		change_color(int color, t_pos xyz, t_win mw, double k);
int		put_shadow(t_pos xyz, double k, t_win mw, int i);
int		rotate_trans(t_pos *, t_win *, int);

# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<math.h>
# include	<mlx.h>
# include	<stdio.h>
# include	<stdlib.h>

#endif
