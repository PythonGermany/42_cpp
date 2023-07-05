# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburgsta <rburgsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 15:38:03 by rburgsta          #+#    #+#              #
#    Updated: 2023/07/05 13:17:03 by rburgsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

DATABASE_DIR = cpp_09/
DATABASE = $(DATABASE_DIR)/data.csv
ARCHIVE = cpp_09.tgz

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp
	c++ -c $(FLAGS) $^

input: $(DATABASE)

$(DATABASE) : $(ARCHIVE)
	tar -xf $(ARCHIVE)

$(ARCHIVE) :
	curl https://cdn.intra.42.fr/document/document/17623/cpp_09.tgz --output $(ARCHIVE)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(DATABASE_DIR)
	rm -rf $(ARCHIVE)

re : fclean all