	# COLORS_TEXT
WHITE	=	\033[0m
BLACK	=	\033[0;30m
RED	=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m
#
B = \033[40m    #чёрный цвет фона
R = \033[41m    #красный цвет фона
G = \033[42m    #зелёный цвет фона
Y = \033[43m    #желтый цвет фона
BL = \033[44m    #синий цвет фона
M = \033[45m    #фиолетовый цвет фона
C = \033[46m    #цвет морской волны фона
W = \033[47m    #серый цвет фона
#
NAME		=	so_long
#
SOURSE		=	so_long.c\
				step_count.c\
				key_control.c\
				gnl/gnl.c\
				gnl/gnl_utils.c\
				draw_map.c\
				map_checker.c\
				solong_utils.c\
				errors.c
# 
CFLAGS		= -Wall -Werror -Wextra -I $(HEADER)
HEADER		= so_long.h

OBJ = $(SOURSE:%.c=%.o)
CC = gcc
#
.PHONY : all clean fclean re bonus music
#
all: $(NAME)
	@echo " $(CYAN)\033[1m-------------------------------------------------------------------"
	@echo "| $(CYAN)\033[1m╔╗╔╗╔╦═══╦╗ ╔══╦══╦╗  ╔╦═══╗ ╔══╦╗ ╔╗ ╔╗  ╔╦╗╔╗ ╔═══╦══╦╗  ╔╦═══╗ |" 
	@echo "| ║║║║║║╔══╣║ ║╔═╣╔╗║║  ║║╔══╝ ╚╗╔╣╚═╝║ ║║  ║║║║║ ║╔══╣╔╗║║  ║║╔══╝ |"  
	@echo "| ║║║║║║╚══╣║ ║║ ║║║║╚╗╔╝║╚══╗  ║║║╔╗ ║ ║╚╗╔╝║╚╝║ ║║╔═╣╚╝║╚╗╔╝║╚══╗ |" 
	@echo "| ║║║║║║╔══╣║ ║║ ║║║║╔╗╔╗║╔══╝  ║║║║╚╗║ ║╔╗╔╗╠═╗║ ║║╚╗║╔╗║╔╗╔╗║╔══╝ |" 
	@echo "| ║╚╝╚╝║╚══╣╚═╣╚═╣╚╝║║╚╝║║╚══╗ ╔╝╚╣║ ║║ ║║╚╝║║╔╝║ ║╚═╝║║║║║╚╝║║╚══╗ |" 
	@echo "| ╚═╝╚═╩═══╩══╩══╩══╩╝  ╚╩═══╝ ╚══╩╝ ╚╝ ╚╝  ╚╝╚═╝ ╚═══╩╝╚╩╝  ╚╩═══╝ |"
	@echo "|                    $(RED)\033[1m╔════╦╗─────╔════╗─────╔╗                	    |"
	@echo "|                    $(RED)\033[1m║╔╗╔╗║║─────╚══╗═║─────║║      		    |"
	@echo "|                    $(RED)\033[1m╚╝║║╚╣╚═╦══╗──╔╝╔╬══╦╗╔╣╚═╦╦══╗     	    |"
	@echo "|                    $(RED)\033[1m──║║─║╔╗║║═╣─╔╝╔╝║╔╗║╚╝║╔╗╠╣║═╣    	    |"
	@echo "|                    $(RED)\033[1m──║║─║║║║║═╣╔╝═╚═╣╚╝║║║║╚╝║║║═╣    	    |"
	@echo "|                    $(RED)\033[1m──╚╝─╚╝╚╩══╝╚════╩══╩╩╩╩══╩╩══╝		    |"
	@echo " $(RED)\033[1m-------------------------------------------------------------------$(RED)"
	@say Hello peer. I am phella. Welcome to my project So long. You can start game the Zombie &
	@afplay "music/Zombie.aac" &
#
$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SOURSE) -o $(NAME)
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
music :
	@killall afplay
#
clean :
	@rm -f $(OBJ)
	@killall afplay
#
fclean : clean
	@rm -f $(NAME)
	@killall afplay
