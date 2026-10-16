/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:53:32 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/02 17:06:14 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./harlFilter <level> <level> ..." << std::endl;
		return 1;
	}

	Harl harl;
	for (int i = 1; i < argc; i++)
	{
		harl.complain(argv[i]);
	}

	return 0;
}