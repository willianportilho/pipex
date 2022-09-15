# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/09/16 01:38:20 by wportilh         ###   ########.fr        #
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

LIBFT =		./libft/libft.a

LIB =		./libft
INC =		./inc

SRC_PATH =		src/
SRC_B_PATH =	src_bonus/

OBJ_PATH =		obj/
OBJ_B_PATH =	obj_bonus/

SRCS =		${addprefix ${SRC_PATH}, ${SOURCES}}
SRCS_B =	${addprefix ${SRC_B_PATH}, ${SOURCES_B}}

OBJS =		${addprefix ${OBJ_PATH}, ${SOURCES:.c=.o}}
OBJS_B =	${addprefix ${OBJ_B_PATH}, ${SOURCES_B:.c=.o}}

ITALIC =	\033[3m
BLACK =		\033[30m
RED =		\033[31m
GREEN =		\033[32m
YELLOW =	\033[33m
BLUE =		\033[34m
PURPLE =	\033[35m
CYAN =		\033[36m
WHITE =		\033[37m
RESET =		\033[0m

all:		${NAME}

${NAME}:	${LIBFT} ${OBJS}
			@echo "${CYAN}----------"
			@echo "OBJS OK!!!"
			@echo "----------${RESET}"
			@${CC} ${OBJS} ${LIBFT} -o ${NAME}
			@echo "${CYAN}------------------------"
			@echo "PIPEX PROGRAM CREATED!!!"
			@echo "------------------------${RESET}"

${OBJ_PATH}%.o:	${SRC_PATH}%.c
				@mkdir -p obj
				@${CC} ${CFLAGS} -c $< -o $@

bonus:		${NAME_B}

${NAME_B}:	${LIBFT} ${OBJS_B}
			@echo "${CYAN}----------"
			@echo "OBJS OK!!!"
			@echo "----------${RESET}"
			@${CC} ${OBJS_B} ${LIBFT} -o ${NAME_B}
			@echo "${CYAN}------------------------"
			@echo "PIPEX PROGRAM CREATED!!!"
			@echo "------------------------${RESET}"

${OBJ_B_PATH}%.o:	${SRC_B_PATH}%.c
				@mkdir -p obj_bonus
				@${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
			@make -C ./libft

clean:		
			@${RM_ALL} ${OBJ_PATH}
			@${RM_ALL} ${OBJ_B_PATH}
			@make clean -C ./libft/
			@echo "${CYAN}------------------"
			@echo "CLEAN COMPLETED!!!"
			@echo "------------------${RESET}"

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${NAME_B}
			@make fclean -C ./libft/
			@echo "${CYAN}-------------------"
			@echo "FCLEAN COMPLETED!!!"
			@echo "-------------------${RESET}"

re:			fclean all
			@echo "${CYAN}---------------"
			@echo "RE COMPLETED!!!"
			@echo "---------------${RESET}"

.PHONY:		all clean fclean re bonus

norm:
			norminette ${SRCS} ${SRCS_B} ${LIB} ${INC}