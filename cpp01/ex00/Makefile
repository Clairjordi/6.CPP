# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorcery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 14:34:41 by clorcery          #+#    #+#              #
#    Updated: 2023/01/23 13:15:48 by clorcery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Zombie.cpp \
	   newZombie.cpp \
	   randomChump.cpp \
	   main.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = Phonebook

FLAGS = -Wall -Werror -Wextra -std=c++98

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
