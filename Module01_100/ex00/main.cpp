/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:34:47 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/02 10:18:30 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <exception>
// #include <new>

// zombie allocated on the free store, that must be deleted manually
Zombie*	newZombie( std::string name );

// standard stack allocation zombie; automatically destroyed when it goes out of scope
void	randomChump( std::string name );

// int	main(void)
// {
// 	Zombie*	heapy = newZombie("Heapy");
// 	std::cout << "   Point of randomChump function call" << std::endl;
// 	randomChump("Stacky");
// 	std::cout << "   Point after randomChump function call" << std::endl;
// 	delete heapy;
// }

int	main(void)
{
	try
	{
		Zombie*	heapy = newZombie("Heapy");
		// throw std::bad_alloc();
		std::cout << "   Point OF randomChump function call" << std::endl;
		randomChump("Stacky");
		std::cout << "   Point AFTER randomChump function call" << std::endl;
		heapy->announce();
		delete heapy;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception cought: " << e.what() <<std::endl;
		return (1);
	}
	return (0);
}
