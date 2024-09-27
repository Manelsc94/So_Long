# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 19:18:39 by mde-agui          #+#    #+#              #
#    Updated: 2024/09/04 12:22:06 by mde-agui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -f
LIBC	=	ar -rcs
INC	=	.
HEADER	=	libft.h

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
				ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_printf.c \
				ft_s_conver.c ft_p_conver.c ft_u_conver.c ft_x_conver.c \
				ft_c_conver.c ft_d_conver.c get_next_line.c get_next_line_utils.c

LIB_SRCS_OBJS	=	$(SRCS:.c=.o)

.c.o :
	${CC} ${CFLAGS} -c $< -o $@ -I${INC}

$(NAME):	$(LIB_SRCS_OBJS)
			$(LIBC) $(NAME) $(LIB_SRCS_OBJS)

all:	$(NAME)

clean:
		$(RM) -f $(LIB_SRCS_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all
