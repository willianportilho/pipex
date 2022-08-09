# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/08/10 00:48:05 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=       \
	ft_isalpha.c \
	ft_isdigit.c  \
	ft_isalnum.c   \
	ft_isascii.c    \
	ft_isprint.c     \
	ft_strlen.c       \
	ft_memset.c        \
	ft_bzero.c          \
	ft_memcpy.c          \
	ft_memmove.c          \
	ft_strlcpy.c           \
	ft_strlcat.c            \
	ft_toupper.c             \
	ft_tolower.c              \
	ft_strchr.c                \
	ft_strrchr.c                \
	ft_strncmp.c                 \
	ft_memchr.c                   \
	ft_memcmp.c                    \
	ft_strnstr.c                    \
	ft_atoi.c                        \
	ft_calloc.c                       \
	ft_strdup.c                        \
	ft_substr.c                         \
	ft_strjoin.c                         \
	ft_strtrim.c                          \
	ft_split.c                             \
	ft_itoa.c                               \
	ft_strmapi.c                             \
	ft_striteri.c                             \
	ft_putchar_fd.c                            \
	ft_putstr_fd.c                              \
	ft_putendl_fd.c                              \
	ft_putnbr_fd.c                                \
	get_next_line.c                                \
	get_next_line_utils.c                           \
	ft_printf.c                                      \
	ft_print_c.c                                      \
	ft_print_d_i.c                                     \
	ft_print_p.c                                        \
	ft_print_s.c                                         \
	ft_print_u.c                                          \
	ft_print_x_lower.c                                     \
	ft_print_x_upper.c                                      \
	ft_pre_c.c                                               \
	ft_pre_d_i.c                                              \
	ft_pre_p.c                                                 \
	ft_pre_s.c                                                  \
	ft_pre_u.c                                                   \
	ft_pre_x_lower.c                                              \
	ft_pre_x_upper.c

SRCBONUS	=                                                        \
	ft_lstnew.c                                                       \
	ft_lstadd_front.c                                                  \
	ft_lstsize.c                                                        \
	ft_lstlast.c                                                         \
	ft_lstadd_back.c                                                      \
	ft_lstdelone.c                                                         \
	ft_lstclear.c                                                           \
	ft_lstiter.c                                                             \
	ft_lstmap.c

OBJ			= ${SRC:.c=.o}

OBJBONUS	= ${SRCBONUS:.c=.o}

NAME		= libft.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

CREATE		= ar rc

RM			= rm -f

${NAME}:	${OBJ}
			@${CREATE} ${NAME} ${OBJ}
			@echo "================="
			@echo "LIBFT COMPILED!!!"
			@echo "================="
			@sleep 2

.c.o:		
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

bonus:		${OBJBONUS}
			@${CREATE} ${NAME} ${OBJBONUS}
			@echo "================="
			@echo "LIBFT_BONUS COMPILED!!!"
			@echo "================="
			@sleep 2

clean:
			@${RM} ${OBJ} ${OBJBONUS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re