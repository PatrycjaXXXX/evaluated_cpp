# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/26 16:27:51 by psmolich          #+#    #+#              #
#    Updated: 2026/09/26 16:27:54 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= megaphone

#https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
# CXX and CXXFLAGS are built-in Makefile variables
CXX		 := c++
CXXFLAGS	= -Wall -Wextra -Werror $(CXXSTD)

# Custom variable for the standard, normally standard is dictated by compiler
# list of supported standards: https://gcc.gnu.org/onlinedocs/gcc/Standards.html
CXXSTD	  := -std=c++98

SRCS		= megaphone.cpp
OBJS		= $(SRCS:%.cpp=%.o)
RM		  = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	./megaphone "shhhhh... I think the students are asleep..." >> test
	@echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." >> correct
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off." >> test
	@echo "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." >> correct
	./megaphone >> test
	@echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *" >> correct
	@diff test correct && echo "Test passed" || echo "Test failed, see diff above"
	@$(RM) test correct
	
# &&: Acts as a conditional branch. The command after && runs only if the previous command succeeded 
# 	(returned exit code 0, meaning files are identical).
# ||: Acts as the alternative branch. The command after || runs only if the previous chain failed
# 	(returned a non-zero exit code, meaning files are different or an error occurred).

.PHONY: all clean fclean re test
