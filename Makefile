# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 07:22:21 by aelabid           #+#    #+#              #
#    Updated: 2023/01/30 22:36:01 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = vector/testVector.cpp

OBJ = $(SRC:.cpp=.o)

NAME = containers

CFLAGS = -Wall -Wextra -Werror
CC = c++

all : $(NAME)


%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)


clean :
	rm -f $(OBJ) 

fclean : clean
	rm -rf $(NAME) 

re : fclean all 
