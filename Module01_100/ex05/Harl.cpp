/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:54:34 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/02 16:56:54 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void)
{
	std::cout << DEBUG_BG << DEBUG_MSG << RESET << std::endl;
}

void	Harl::_info(void)
{
	std::cout << INFO_BG << INFO_MSG << RESET << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << WARNING_BG << WARNING_MSG << RESET << std::endl;
}

void	Harl::_error(void)
{
	std::cout << ERROR_BG << ERROR_MSG << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	HarlFuncPtrArr	funcs = {&Harl::_debug,
							&Harl::_info,
							&Harl::_warning,
							&Harl::_error};
	std::string	levels[NUM_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < NUM_LEVELS; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	// std::cout << "Unknown level: " << level << std::endl;
}