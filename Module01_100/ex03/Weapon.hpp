/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:24:31 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/02 14:15:36 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class	Weapon
{
	public:
		Weapon(std::string type);
		const std::string&	getType(void) const;
//       |               |
//      const          reference
		void				setType(std::string type);
	private:
		std::string			_type;
} ;

#endif