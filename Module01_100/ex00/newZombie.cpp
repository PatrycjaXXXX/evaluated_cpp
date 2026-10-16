/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:20:43 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/02 10:06:47 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// #include <new>

Zombie*	newZombie( std::string name )
{
	// throw std::bad_alloc();
	return (new Zombie(name));
}