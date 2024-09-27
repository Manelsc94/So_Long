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
MLX_FLAGS		=	-L./minilibx-linux -lmlx -lm -lXext -lX11 -I./minilibx-linux
INC				=	.
HEADER			=	so_long.h
HEADER_BONUS	=	so_long_bonus.h
LIBFT			=	./libft/libft.a
NAME			=	so_long/so_long
NAME_BONUS		=	so_long_bonus/so_long_bonus

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

MLX			=	minilibx-linux

.PHONY: all clean fclean re mlx bonus

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -I./minilibx-linux -c $< -o $@

mlx:
	$(MAKE) -C ./minilibx-linux

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT) mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) mlx
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx-linux

fclean: clean
		$(RM) -f $(NAME) $(NAME_BONUS)
		$(MAKE) fclean -C ./libft

re: fclean all