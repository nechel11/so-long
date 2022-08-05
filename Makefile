
MINILIBX_PATH	=	./minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	= ft_split.c ft_strjoin.c ft_strdup.c\
					  game_init.c get_next_line.c \
					  get_next_line_utils.c img_print.c \
					  map_reading.c map_validate.c \
					  so_long.c utils.c gaming.c \
					  player_movements.c map_clear.c\

SOURCES_DIR		=	src

HEADER			=	$(SOURCES_DIR)/so_long.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	so_long

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -O0 -g
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)


$(NAME):		$(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re minilibx
