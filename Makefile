# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/08/10 00:57:14 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	            \
			main.c       \
			pipex_clean.c \
			pipex_cmd_arg.c\
			pipex_cmd_path.c\
			pipex_error.c    \
			pipex.c

SOURCES_B =	            \
			main_bonus.c       \
			pipex_clean_bonus.c \
			pipex_cmd_arg_bonus.c\
			pipex_cmd_path_bonus.c\
			pipex_error_bonus.c    \
			pipex_bonus.c

NAME =		pipex
NAME_B =	pipex_bonus

CC =		cc
CFLAGS =	-g3 -Wall -Wextra -Werror
RM =		rm -f
RM_ALL =	rm -rf

VAL =		valgrind --leak-check=full --show-leak-kinds=all

LIBFT =		./libft/libft.a

SRC_PATH =			src/
SRC_B_PATH =		src_bonus/

OBJ_PATH =			obj/
OBJ_B_PATH =		obj_bonus/

SRCS =		${addprefix ${SRC_PATH}, ${SOURCES}}
SRCS_B =	${addprefix ${SRC_B_PATH}, ${SOURCES_B}}

OBJS =		${addprefix ${OBJ_PATH}, ${SOURCES:.c=.o}}
OBJS_B =	${addprefix ${OBJ_B_PATH}, ${SOURCES_B:.c=.o}}

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

bonus:		${NAME_B}

${NAME_B}:	${LIBFT} ${OBJS_B}
			@echo "================"
			@echo "OBJS BONUS OK!!!"
			@echo "================"
			@sleep 2
			${CC} ${OBJS_B} ${LIBFT} -o ${NAME_B}
			@echo "=============================="
			@echo "PIPEX BONUS PROGRAM CREATED!!!"
			@echo "=============================="
			@sleep 2

${OBJ_B_PATH}%.o:	${SRC_B_PATH}%.c
				@mkdir -p obj_bonus
				@${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
			make -C ./libft

clean:		
			@${RM_ALL} ${OBJ_PATH}
			@${RM_ALL} ${OBJ_B_PATH}
			@make clean -C ./libft/
			@echo "=================="
			@echo "CLEAN COMPLETED!!!"
			@echo "=================="
			@sleep 2

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${NAME_B}
			@make fclean -C ./libft/
			@echo "==================="
			@echo "FCLEAN COMPLETED!!!"
			@echo "==================="
			@sleep 2

re:			fclean all
			@echo "==============="
			@echo "RE COMPLETED!!!"
			@echo "==============="
			@sleep 2

rebonus:	fclean bonus
			@echo "===================="
			@echo "REBONUS COMPLETED!!!"
			@echo "===================="
			@sleep 2

.PHONY:		all bonus clean fclean re rebonus

norm:
			norminette ${SRCS} ${SRCS_B}