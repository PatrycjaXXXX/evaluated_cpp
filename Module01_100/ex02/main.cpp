/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 10:42:33 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/02 11:22:45 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#define PURPLE_BG "\033[45m"
#define RESET "\033[0m"

/*
reference is an alias (alternative name) for an already existing variable
reference must be initialized at the moment of declaration
reference cannot be reassigned to another variable
example:
after int i = 8; int& j = i;
j = 7; would be the same as i = 7;
*/

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN"; // A string variable initialized to "HI THIS IS BRAIN".
	std::string*	stringPTR = &string; // stringPTR: a pointer to the string
	std::string&	stringREF = string; // stringREF: a reference to the string
	
	std::cout << PURPLE_BG << "\nYour program must print:\n" << RESET;
	std::cout << std::setw(50) << "The memory address of the string variable: " << &string << std::endl;
	std::cout << std::setw(50) << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << std::setw(50) << "The memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << PURPLE_BG << "And then:\n" << RESET;
	std::cout << std::setw(50) <<"The value of the string variable: " << string << std::endl;
	std::cout << std::setw(50) <<"The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << std::setw(50) <<"The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}