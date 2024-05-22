NAME	=	so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror # -g -fsanitize=address
MFLAGS	=	-L./mlx_mac -lmlx -framework OpenGL -framework AppKit #-lz
IFLAGS	=	-I. -I./libft -I./mlx_mac
LFLAGS	=	-L./libft -lft
BFLAGS	=	0

MLX_DIR	=	./mlx_mac
MLX		=	libmlx.dylib

SRC		=	main.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			utils.c \
			press.c \
			parsing.c \
			move.c \
			init.c \
			exit.c \


OBJ		=	$(SRC:%.c=%.o)

%.o: %.c
			$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ -D BONUS=$(BFLAGS)
			
ifeq ($(shell uname), Linux)
$(NAME): IFLAGS = -I. -I./libft -I./mlx_linux
$(NAME): MFLAGS	= -L./mlx_linux -lmlx_Linux -lXext -lX11
$(NAME): MLX_DIR = ./mlx_linux
$(NAME): MLX = libmlx.a
endif

$(NAME):	$(OBJ)
			$(MAKE) -C ./$(MLX_DIR)
			cp ./$(MLX_DIR)/$(MLX) .
			$(MAKE) -C libft
			$(CC) $(CFLAGS) $(OBJ) $(IFLAGS) $(LFLAGS) $(MFLAGS) -o $@


all:		$(NAME)

bonus:		BFLAGS = 1
bonus:		$(NAME)

clean:
			$(MAKE) -C libft clean
			rm -rf $(OBJ)

ifeq ($(shell uname), Linux)
fclean: MLX_DIR = ./mlx_linux
fclean: MLX = libmlx.a
endif

fclean:		clean
			$(MAKE) -C libft fclean
			$(MAKE) -C ./$(MLX_DIR) clean
			rm -rf $(MLX)
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re