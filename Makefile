# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 07:22:21 by aelabid           #+#    #+#              #
#    Updated: 2023/03/01 11:36:43 by aelabid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = vector/testVector.cpp

OBJ = $(SRC:.cpp=.o)

NAME = containers

CFLAGS = -Wall -Wextra -Werror
CC = c++

all : $(NAME)


%.o: %.cpp
	$(CC) -c $<  -o $@ 
	
$(NAME) : $(OBJ)
	$(CC) -fsanitize=address $(OBJ) -o $(NAME)


clean :
	rm -f $(OBJ) 

fclean : clean
	rm -rf $(NAME) 

re : fclean all 
