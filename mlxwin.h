/*
** tp1_click_pixel.h for my_click_pixel in /home/woivre_t/Tp_epitech/Igraph
**
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
**
** Started on  Fri Oct 25 11:49:50 2013 Thibault Woivre
** Last update Tue May 27 17:58:14 2014 arthur vincent
*/

#ifndef		MLXWIN_H_
# define	MLXWIN_H_

# define BLUEF	0x384592
# define BLUEC	0x2196E0
# define VIOLET	0xb73de3
# define GREEN	0x63ca59
# define YELLOW	0xe9d23c
# define ORANGE	0xf39438
# define RED	0xda3230
# define WHITE	0xFFFFFF
# define BLACK	0x000000

typedef struct	s_calc
{
  double	k;
  double	x;
  double	y;
  double	z;
  double	k2;
  double	x2;
  double	y2;
  double	z2;
}		t_calc;

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
  void		*img_wait;
  t_obj		*tab_obj;
  t_lum		*tab_lum;
  t_pos		p_oeil;
  t_pos		r_oeil;
}		t_win;

void		aff_poney(int x, int y, t_win *mlxwin);
void		aff_wait_bar(int, int, int, t_win *mlxwin);
void		calcul_cylindre(double *var, t_pos *xyz, t_win *mw, int i);
void		inter_disque_cone(t_pos xyz, t_win mw, t_calc *disc, int i);
void		inter_disque_cyl(t_pos xyz, t_win mw, t_calc *disc, int i);
void		inter_disque(t_pos xyz, t_win mw, t_calc *disc, int i);
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
int		change_color(int *var, t_pos xyz, t_win mw, double k);
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
