# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/26 16:28:04 by psmolich          #+#    #+#              #
#    Updated: 2026/09/26 16:39:09 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= phonebook

#https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
# CXX and CXXFLAGS are built-in Makefile variables
CXX			:= c++
CXXFLAGS	= -Wall -Wextra -Werror $(CXXSTD)

# Custom variable for the standard, normally standard is dictated by compiler
# list of supported standards: https://gcc.gnu.org/onlinedocs/gcc/Standards.html
CXXSTD		:= -std=c++98

SRCS		= main.cpp PhoneBook.cpp Contact.cpp
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