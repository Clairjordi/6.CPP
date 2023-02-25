# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorcery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 10:44:17 by clorcery          #+#    #+#              #
#    Updated: 2023/02/25 18:02:22 by clorcery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp \
	   Bureaucrat.cpp \
	   Form.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp

OBJS = ${SRCS:.cpp=.o}

NAME =  bureaucrat

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
