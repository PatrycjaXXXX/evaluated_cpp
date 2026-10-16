/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 06:00:42 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/03 10:11:40 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "replace.hpp"
#define YELLOW_BG "\033[43m"
#define RESET "\033[0m"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./Sed_is_for_losers <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	
	const std::string	filename = argv[1];
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];
	
	std::ifstream		infile; // filename
	std::ofstream		outfile; // .replace
	std::string			buffer;
	
	// Open the input file for reading; use default flag: std::ios::in
	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << YELLOW_BG << "Error: Could not open file " << filename << RESET << std::endl;
		return (1);
	}
	/*
	                                                default
                                                       |
	Open the output file for writing; use flags: std::ios::out | std::ios::trunc
	if file already exists, it will be truncated to zero length; if it does not exist, a new file will be created
	*/
	outfile.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc); 
	if (!outfile.is_open())
	{
		std::cerr << YELLOW_BG << "Error: Could not create file " << filename << ".replace" << RESET << std::endl;
		return (1);
	}

	/*
	** s1 containing a newline is intentionally not supported.
	** The file is processed line by line (std::getline strips '\n'),
	** which matches the default behavior of sed. Matching across lines
	** would require reading the whole file into memory.
	*/
	while (std::getline(infile, buffer))
	{
		replace(buffer, s1, s2);
		if (!infile.eof())
			buffer += '\n';
		outfile << buffer;
	}
	return (0);
}