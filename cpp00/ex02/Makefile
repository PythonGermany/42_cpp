# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburgsta <rburgsta@student.42.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 15:38:03 by rburgsta          #+#    #+#              #
#    Updated: 2023/02/07 03:29:05 by rburgsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests

FLAGS = -Wall -Wextra -Werror -std=c++98
LK_SAN = #-Wno-gnu-include-next -I/LeakSanitizer/include -L../../LeakSanitizer/ -llsan -lc++

SRC = tests.cpp Account.cpp
OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(LK_SAN) -o $(NAME) $(OBJ)

%.o : %.cpp
	c++ -c $(FLAGS) $^

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all