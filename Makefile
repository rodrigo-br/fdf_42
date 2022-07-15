SRC		=	ft_fdf.c

H_SRC	=	ft_fdf.h

OBJS	=	${SRC:.c=.o}

NAME	=	fdf

FLAGS	=	-Wall -Wextra #-Werror

RM		=	rm -f

IFT		= -Ilibft -Llibft -lft

IMLX	= -Imlx -Lmlx -lmlx -lXext -lX11 -lm

.c.o:
			cc ${FLAGS} -c $< ${IFT} ${IMLX} -o ${<:.c=.o} -I.

$(NAME):	${OBJS} ${H_SRC}
			make -C ./printf
			mv ./printf/libftprintf.a ./$(NAME)

all: 		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ./printf

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re