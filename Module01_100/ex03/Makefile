# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/02 14:27:20 by psmolich          #+#    #+#              #
#    Updated: 2026/10/16 14:13:10 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Unnecessary_violence

#https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
# CXX and CXXFLAGS are built-in Makefile variables
CXX			:= c++
CXXFLAGS	= -Wall -Wextra -Werror $(CXXSTD)

# Custom variable for the standard, normally standard is dictated by compiler
# list of supported standards: https://gcc.gnu.org/onlinedocs/gcc/Standards.html
CXXSTD		:= -std=c++98

SRCS		= HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
OBJS_DIR	= obj
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re