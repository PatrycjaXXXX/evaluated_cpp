/* ************************************************************************************************************************************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 20:09:06 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/02 10:28:57 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ******************************************************************************* */

#include "Zombie.hpp"
# ifndef HORDE_SIZE
#  define HORDE_SIZE 10
# endif
# ifndef ZOMBIE_NAME
#  define ZOMBIE_NAME "Patrycja"
# endif


Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	const int N = HORDE_SIZE;
	const std::string name = ZOMBIE_NAME;
	
	std::cout << PURPLE_BG << "******** Call zombieHorde ********" << RESET << std::endl;
	Zombie*	horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	std::cout << PURPLE_BG << "******** Change the name of first one ********" << RESET << std::endl;
	horde->setName("First");
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}