# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/08/10 05:52:07 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	            \
			main.c       \
			pipex_clean.c \
			pipex_cmd_arg.c\
			pipex_cmd_path.c\
			pipex_error.c    \
			pipex.c

NAME =		pipex

CC =		cc
CFLAGS =	-g3 -Wall -Wextra -Werror
RM =		rm -f
RM_ALL =	rm -rf

VAL =		valgrind --leak-check=full --show-leak-kinds=all

LIBFT =		./libft/libft.a

SRC_PATH =			src/
OBJ_PATH =			obj/

SRCS =		${addprefix ${SRC_PATH}, ${SOURCES}}
OBJS =		${addprefix ${OBJ_PATH}, ${SOURCES:.c=.o}}

all:		${NAME}

${NAME}:	${LIBFT} ${OBJS}
			@echo "=========="
			@echo "OBJS OK!!!"
			@echo "=========="
			@sleep 2
			@${CC} ${OBJS} ${LIBFT} -o ${NAME}
			@echo "========================"
			@echo "PIPEX PROGRAM CREATED!!!"
			@echo "========================"
			@sleep 2

${OBJ_PATH}%.o:	${SRC_PATH}%.c
				@mkdir -p obj
				@${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
			make -C ./libft

clean:		
			@${RM_ALL} ${OBJ_PATH}
			@make clean -C ./libft/
			@echo "=================="
			@echo "CLEAN COMPLETED!!!"
			@echo "=================="
			@sleep 1

fclean:		clean
			@${RM} ${NAME}
			@make fclean -C ./libft/
			@echo "==================="
			@echo "FCLEAN COMPLETED!!!"
			@echo "==================="
			@sleep 1

re:			fclean all
			@echo "==============="
			@echo "RE COMPLETED!!!"
			@echo "==============="
			@sleep 1

.PHONY:		all bonus clean fclean re

norm:
			norminette ${SRCS}