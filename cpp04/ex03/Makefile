# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorcery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 10:44:17 by clorcery          #+#    #+#              #
#    Updated: 2023/02/15 19:51:08 by clorcery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp \
	   AMateria.cpp \
	   Ice.cpp \
	   Cure.cpp \
	   Character.cpp \
	   MateriaSource.cpp

OBJS = ${SRCS:.cpp=.o}

NAME =  materia

FLAGS = -Wall -Werror -Wextra -std=c++98 -g

all: ${NAME}

.cpp.o:
		c++ ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
		c++ ${FLAGS} ${OBJS} -o ${NAME}

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
