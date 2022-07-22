SRC		=	exit.c parse_map.c bresenham.c ft_n_max.c screen.c \
			hooks.c colour.c rotate.c bresenham_utils.c

H_SRC	=	ft_fdf.h

OBJS	=	$(addprefix srcs/, ${SRC:.c=.o})

NAME	=	fdf_binary

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

IFT		= -Ilibft -Llibft

IMLX	= -Imlx -Lmlx -lmlx -lXext -lX11 -lm

.c.o:
			cc ${FLAGS} -c $< ${IFT} ${IMLX} -o ${<:.c=.o} -I.

$(NAME):	${OBJS} ${H_SRC}
			make -C ./printf
			mv ./printf/libftprintf.a ./$(NAME)
			cc -g3 $(addprefix srcs/, ${SRC}) ./srcs/main.c ${NAME} ${IFT} ${IMLX} -o fdf

all: 		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ./printf

fclean:		clean
			${RM} ${NAME}
			${RM} fdf

re:			fclean all

bonus:		${NAME}

.PHONY:		all clean fclean re