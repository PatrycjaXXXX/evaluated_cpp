# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/02 15:51:20 by psmolich          #+#    #+#              #
#    Updated: 2026/10/16 14:32:43 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Harl_2.0

#https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
# CXX and CXXFLAGS are built-in Makefile variables
CXX			:= c++
CXXFLAGS	= -Wall -Wextra -Werror $(CXXSTD)

# Custom variable for the standard, normally standard is dictated by compiler
# list of supported standards: https://gcc.gnu.org/onlinedocs/gcc/Standards.html
CXXSTD		:= -std=c++98

SRCS		= Harl.cpp main.cpp
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

test: all
	@echo "Running tests..."
	@echo "\n\ntest 1 =============================="
	./$(NAME) DEBUG
	@echo "\n\ntest 2 =============================="
	./$(NAME) INFO
	@echo "\n\ntest 3 =============================="
	./$(NAME) WARNING
	@echo "\n\ntest 4 =============================="
	./$(NAME) ERROR
	@echo "\n\ntest 5 =============================="
	./$(NAME) DEBUG INFO WARNING ERROR
	@echo "\n\ntest 6 =============================="
	valgrind -s ./$(NAME) DEBUG INFO WARNING ERROR DEBUG INFO DEBUG WARNING ERROR DEBUG INFO DEBUG WARNING ERROR DEBUG INFO DEBUG WARNING ERROR

.PHONY: all clean fclean re test