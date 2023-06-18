# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 15:38:03 by rburgsta          #+#    #+#              #
#    Updated: 2023/06/18 15:34:27 by rburgsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ScalarConverter.cpp
OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

test:
	c++ $(FLAGS) -o $(NAME) test.cpp ScalarConverter.cpp

$(NAME) : $(OBJ)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp
	c++ -c $(FLAGS) $^

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all