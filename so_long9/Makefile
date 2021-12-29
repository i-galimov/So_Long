NAME = so_long

SRCS = maps.c \
			gnl.c \
			so_long.c \
			utils1.c \
			utils.c \
			move.c \
			checkmap.c \
			checkmap1.c \
			countmove.c
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

FlAGS = -lmlx -framework OpenGL -framework AppKit
CC = gcc
all : $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)



clean : 
	$(RM) $(NAME)


re : clean all