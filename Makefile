# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 12:38:13 by obelair           #+#    #+#              #
#    Updated: 2021/05/31 10:30:20 by obelair          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# === Name === #

NAME		=	skycrapers

# === Directories === #

PATH_LIBFT	=	libft
PATH_HEADERS=	incs
PATH_SRCS	=	srcs
PATH_OBJS	=	objs


# === Compil === #

CC			=	gcc
RENAME		=	-o ${NAME}
CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address
INCS		=	-I${PATH_HEADERS} -I${PATH_LIBFT}/${PATH_HEADERS}
LIBS		=	${PATH_LIBFT}/libft.a
RM			=	rm -rf

# === Sources === #

SRCS		=	${addprefix ${PATH_SRCS}/, main.c error.c parsing.c init.c print.c pre_fill.c find.c view.c utils.c}

# === Objects === #

OBJS		=	${addprefix ${PATH_OBJS}/, ${notdir ${SRCS:.c=.o}}}

# === Include === #

HEADERS		=	${addprefix ${PATH_HEADERS}/, skycrapers.h}

# === Colors === #

_END		=	\033[0m
_BOLD		=	\033[1m
_DIM		=	\033[2m
_UNDERLINE	=	\033[3m

_RED		=	\033[31m
_GREEN		=	\033[32m
_YELLOW		=	\033[33m
_CYAN		=	\033[36m
_LIGHTGRAY	=	\033[37m
_DARKGRAY	=	\033[90m
_LIGHTRED	=	\033[91m

# === Default === #

all:	init ${NAME}

# === Commands === #

${PATH_OBJS}/%.o: ${PATH_SRCS}/%.c ${HEADERS}
	@ echo " ${_GREEN}${_DIM}\\\\\ ${_END}${_GREEN}Compilation done!${_DIM} //${_CYAN}   --->   ${_END}${_YELLOW}| ${_BOLD}${_CYAN}$<${_END} "
	@ ${CC} ${CFLAGS} -c $< -o $@ ${INCS}

init:	
	@ ${shell mkdir -p ${PATH_OBJS}}
	@ ${MAKE} -C ${PATH_LIBFT}

${NAME}: ${OBJS} ${PATH_LIBFT}/libft.a
	@ echo "\n${_LIGHTRED}${_BOLD}${_DIM}$?${_END}\n" \
		"\t ${_YELLOW}${_DIM}${_BOLD}Add to ${NAME}!${_END} \n"
	@ ${CC} ${RENAME} ${CFLAGS} ${OBJS} ${LIBS}

# === Clean === #

clean:	
	@echo "${_LIGHTRED}${_DIM}.o files clean!${_END}"
	@ ${MAKE} clean -C ${PATH_LIBFT}
	@ ${RM} ${PATH_OBJS}

fclean :	clean
	@ echo "${_LIGHTRED}${_DIM}${NAME} clean!${_END}"
	@ ${MAKE} fclean -C ${PATH_LIBFT}
	@ ${RM} ${NAME}

re :	fclean all

.PHONY :	all clean fclean re