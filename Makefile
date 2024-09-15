NAME= so_long

CC= cc
CFLAGS= -c -Wall -Werror -Wextra
AR= ar rcs
RM= rm -rf

all: 
	gcc map_utils.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -Llibft -lft
	./a.out