# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/02 15:51:20 by psmolich          #+#    #+#              #
#    Updated: 2026/10/16 14:26:20 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Sed_is_for_losers

#https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
# CXX and CXXFLAGS are built-in Makefile variables
CXX			:= c++
CXXFLAGS	= -Wall -Wextra -Werror $(CXXSTD)

# Custom variable for the standard, normally standard is dictated by compiler
# list of supported standards: https://gcc.gnu.org/onlinedocs/gcc/Standards.html
CXXSTD		:= -std=c++98

SRCS		= main.cpp replace.cpp
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
	$(RM) -r $(OBJS_DIR) $(TEST_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

TEST_DIR	= tests
TEST_FILE1	= $(TEST_DIR)/hello.txt
TEST_FILE2	= $(TEST_DIR)/empty.txt
TEST_FILE3	= $(TEST_DIR)/nonexistent.txt
TEST_FILE4	= $(TEST_DIR)/newline.txt
S1			= world
S2			= 42
NEWLINE		= \n

test: $(NAME)
	@mkdir -p $(TEST_DIR)
	
	@printf '\nTESTING: $(NAME) with input file $(TEST_FILE1)\n'
	@printf 'hello world\nworld world\nno match here\n\nworldworld end\nlast line world' > $(TEST_FILE1)
	@sed 's/$(S1)/$(S2)/g' $(TEST_FILE1) > $(TEST_FILE1).expected
	@./$(NAME) $(TEST_FILE1) $(S1) $(S2)
	@diff $(TEST_FILE1).replace $(TEST_FILE1).expected && echo "\tTEST OK"
	
	@printf '\nTESTING: $(NAME) with input file $(TEST_FILE2)\n'
	@touch $(TEST_FILE2)
	@sed 's/$(S1)/$(S2)/g' $(TEST_FILE2) > $(TEST_FILE2).expected
	@./$(NAME) $(TEST_FILE2) $(S1) $(S2)
	@diff $(TEST_FILE2).replace $(TEST_FILE2).expected && echo "\tTEST OK"
	
	@printf '\nTESTING: $(NAME) with input file $(TEST_FILE3)\n'
	-@sed 's/$(S1)/$(S2)/g' $(TEST_FILE3)
	-@./$(NAME) $(TEST_FILE3) $(S1) $(S2)

	@printf '\nTESTING: $(NAME) with input file $(TEST_FILE4)\n'
	@printf 'world\nworld\nworld\n' > $(TEST_FILE4)
	@sed 's/$(NEWLINE)/$(S2)/g' $(TEST_FILE4) > $(TEST_FILE4).expected
	@./$(NAME) $(TEST_FILE4) $(NEWLINE) $(S2)
	@diff $(TEST_FILE4).replace $(TEST_FILE4).expected && echo "\tTEST OK"

.PHONY: all clean fclean re test