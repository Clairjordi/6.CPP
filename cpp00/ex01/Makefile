# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorcery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 14:34:41 by clorcery          #+#    #+#              #
#    Updated: 2023/01/21 10:41:42 by clorcery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Phonebook.cpp \
	   Contact.cpp \
	   main.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = phonebook

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
