NAME= so_long

CC= cc
CFLAGS= -c -Wall -Werror -Wextra
AR= ar rcs
RM= rm -rf

all: 
	gcc maps_checker.c map_utils.c test.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -Llibft -lft
	./a.out