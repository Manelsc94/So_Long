# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 19:22:59 by mde-agui          #+#    #+#              #
#    Updated: 2024/09/27 00:28:02 by mde-agui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	. -I./libft
HEADER			=	so_long.h
HEADER_BONUS	=	so_long_bonus.h
LIBFT			=	./libft/libft.a
NAME			=	so_long/so_long
NAME_BONUS		=	so_long_bonus/so_long_bonus

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -I./minilibx-linux
	MLX 	  = minilibx-linux
	MLX_GIT   = https://github.com/42Paris/minilibx-linux.git
else ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -L./minilibx-opengl -lmlx -framework OpenGL -framework AppKit -I./minilibx-opengl
	MLX 	  = minilibx-opengl
	MLX_GIT   = https://github.com/42Paris/minilibx-opengl.git
endif

LIBFT_GIT	=	https://github.com/Manelsc94/Libft.git

SRCS		=	so_long/main.c \
				so_long/utilities/freedom_and_exit.c \
				so_long/utilities/loads_and_checks.c \
				so_long/utilities/other_checks.c \
				so_long/utilities/player_movement.c \
				so_long/foundation/initialization.c \
				so_long/foundation/map_completion.c \
				so_long/foundation/reading_map.c \
				so_long/foundation/validation.c

SRCS_BONUS	=	so_long_bonus/main.c \
				so_long_bonus/utilities/freedom_and_exit.c \
				so_long_bonus/utilities/loads_and_checks.c \
				so_long_bonus/utilities/other_checks.c \
				so_long_bonus/utilities/player_movement.c \
				so_long_bonus/foundation/initialization.c \
				so_long_bonus/foundation/map_completion.c \
				so_long_bonus/foundation/reading_map.c \
				so_long_bonus/foundation/validation.c \
				so_long_bonus/foes/enemy_movement.c \
				so_long_bonus/foes/foe_utilities.c \
				so_long_bonus/foes/patrol_movement.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

.PHONY: all clean fclean re mlx libft bonus

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -I./$(MLX) -c $< -o $@

libft:
	if [ ! -d "./libft" ]; then \
		git clone $(LIBFT_GIT) libft; \
	fi
	$(MAKE) -C ./libft

mlx:
	if [ ! -d "$(MLX)" ]; then \
		git clone $(MLX_GIT) $(MLX); \
	fi
	$(MAKE) -C ./$(MLX)


$(LIBFT): libft

$(NAME): $(LIBFT) mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(LIBFT) mlx $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)
		if [ -d "./libft" ]; then $(MAKE) clean -C ./libft; fi
		if [ -d "./$(MLX)" ]; then $(MAKE) clean -C ./$(MLX); fi

fclean: clean
		$(RM) -f $(NAME) $(NAME_BONUS)
		if [ -d "./libft" ]; then $(MAKE) fclean -C ./libft; fi
		$(RM) -rf ./libft
		$(RM) -rf ./$(MLX)

re: fclean all
