# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 07:22:21 by aelabid           #+#    #+#              #
#    Updated: 2023/03/05 05:32:19 by aelabid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main/main_s.cpp main/main_v.cpp main/main.cpp main/main_m.cpp

OBJ = $(SRC:.cpp=.o)

NAME = containers

CFLAGS = -Wall -Wextra -Werror
CC = c++

all : $(NAME)


%.o: %.cpp vector/vector.hpp map/map.hpp iterators/iterator_traits.hpp iterators/map_it.hpp iterators/vector_it.hpp avl/avl.hpp
	$(CC) $(CFLAGS) -c $<  -o $@ 
	
$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ) 

fclean : clean
	rm -rf $(NAME) 

re : fclean all 
