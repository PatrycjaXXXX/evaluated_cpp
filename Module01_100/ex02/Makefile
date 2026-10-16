# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/02 10:42:36 by psmolich          #+#    #+#              #
#    Updated: 2026/10/16 14:05:55 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= HI_THIS_IS_BRAIN
#https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
# CXX and CXXFLAGS are built-in Makefile variables
CXX			:= c++
CXXFLAGS	= -Wall -Wextra -Werror $(CXXSTD)

# Custom variable for the standard, normally standard is dictated by compiler
# list of supported standards: https://gcc.gnu.org/onlinedocs/gcc/Standards.html
CXXSTD		:= -std=c++98

SRC			= main.cpp
OBJ			= main.o
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re