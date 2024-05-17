SRCS_DIR	:=		srcs
OBJS_DIR	:=		objs

NAME		=		GameOfLife

SRCS		=		srcs/main.c \
					srcs/put_pixel_img.c \
					srcs/init_img.c \
					srcs/destroy_image.c \
					srcs/init.c


OBJS		=	$(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

CC			=		clang
MLX			=		-L./minilibx-linux
MLXFLAGS	=		-lm -lmlx -lX11 -lXext
CFLAGS		=		-Wall -Werror -Werror -I./inc -g3

$(NAME):	$(OBJS) 
				$(MAKE) -C minilibx-linux
				$(CC) $(CFLAGS) $(CPPFLAGS) $(MLX) $^ $(MLXFLAGS) -o $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

all:				$(NAME)


clean:
			rm -rf $(OBJS_DIR)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
