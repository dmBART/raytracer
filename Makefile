##
## Makefile for Makefile in /home/woivre_t/Tp_epitech/Igraph
##
## Made by Thibault Woivre
## Login   <woivre_t@epitech.net>
##
## Started on  Thu Oct 24 16:59:55 2013 Thibault Woivre
## Last update Tue May 27 18:00:18 2014 arthur vincent
##

NAME    	= rtv1

SRC     	= rtv1.c \
		  ombre.c \
		  get_obj.c \
		  get_alum.c \
		  manuel.c \
		  fct_inter.c \
		  fct_inter2.c \
		  get_eye.c \
		  trans_rot.c \
		  fct_inter_cylindre.c \
		  fct_inter_cone.c \
		  luminosite.c \
		  norme.c \
		  wait_bar.c \
		  my_pixel_put_to_image.c \
		  source/get_next_line.c \
		  source/my_str_isnum.c \
		  source/my_show_wordtab.c \
		  source/my_strlen_wordtab.c \
		  source/my_getnbr.c \
		  source/my_free_wordtab.c \
		  source/my_str_to_wordtab.c \
		  source/my_strncpy.c \
		  source/my_putstr.c \
		  source/my_putchar.c \
		  source/my_put_nbr.c \
		  source/xmalloc.c \
		  poney/poney.c \
		  poney/poney2.c \
		  poney/poney3.c \
		  poney/poney4.c \
		  poney/poney5.c \
		  poney/poney6.c \
		  poney/poney_archi.c

OBJ		= $(SRC:.c=.o)

CFLAGS		= -g

LIBX		= -L/usr/lib69 -lmlx_$(HOSTTYPE) -L/usr/lib69/X11 -lXext -lX11

all:		$(NAME)

$(NAME): 	$(OBJ)
		cc $(CFLAGS) $(OBJ) -o $(NAME) $(LIBX) -lm

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
