/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 20:07:08 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/02 11:33:03 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define PURPLE_BG "\033[45m"
#define RESET "\033[0m"

class	Zombie
{
	public:
		Zombie();
		~Zombie();
		void		announce ( void );
		void		setName(std::string name);
	private:
		std::string	_name;
} ;

#endif