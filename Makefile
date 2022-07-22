# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/07/22 17:38:06 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	main.c

NAME =		pipex

CC =		cc
CFLAGS =	-g -Wall -Wextra -Werror
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
			${CC} ${OBJS} ${LIBFT} -o ${NAME}

${OBJ_PATH}%.o:	${SRC_PATH}%.c
				mkdir -p obj
				${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:	
			@echo "compiling"
			make -C ./libft
			@echo "libft compiled"

clean:		
			${RM_ALL} ${OBJ_PATH}
			make clean -C ./libft/

fclean:		clean
			${RM} ${NAME}
			make fclean -C ./libft/

re:			fclean all

rebonus:	fclean bonus

run:		${NAME}
			${VAL} ./${NAME}

.PHONY:		all clean fclean re  run

norm:
			norminette ${SRCS}