##
## Makefile for Makefile in /home/woivre_t/Tp_epitech/Igraph
## 
## Made by Thibault Woivre
## Login   <woivre_t@epitech.net>
## 
## Started on  Thu Oct 24 16:59:55 2013 Thibault Woivre
## Last update Sun Mar 16 20:44:52 2014 Thibault Woivre
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
		  source/xmalloc.c

OBJ		= $(SRC:.c=.o)

FLAGS		= -ansi -pedantic -w -Wall

LIBX		= -L/usr/lib69 -lmlx_$(HOSTTYPE) -L/usr/lib69/X11 -lXext -lX11

all:		$(NAME)

$(NAME): 	$(OBJ)
		cc $(FLAGS) $(OBJ) -o $(NAME) $(LIBX) -lm

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
