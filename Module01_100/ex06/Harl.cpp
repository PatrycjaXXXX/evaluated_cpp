/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:10:24 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/16 14:37:27 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void)
{
	std::cout << "[DEBUG]\n"<< DEBUG_BG << DEBUG_MSG << RESET << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[INFO]\n"<< INFO_BG << INFO_MSG << RESET << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[WARNING]\n"<< WARNING_BG << WARNING_MSG << RESET << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ERROR]\n"<< ERROR_BG << ERROR_MSG << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	HarlFuncPtrArr	funcs = {&Harl::_debug,
							&Harl::_info,
							&Harl::_warning,
							&Harl::_error};
	std::string	levels[NUM_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < NUM_LEVELS && levels[i] != level)
		i++;
	//switch can only use int, char, or enum types, so i can't use it with std::string
	switch (i)
	{
		case 0:
			(this->*funcs[0])();
			//fall-through
		case 1:
			(this->*funcs[1])();
			//fall-through
		case 2:
			(this->*funcs[2])();
			//fall-through
		case 3:
			(this->*funcs[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

// void	Harl::complain(std::string level)
// {
// 	HarlFuncPtrArr	funcs = {&Harl::_debug,
// 							&Harl::_info,
// 							&Harl::_warning,
// 							&Harl::_error};
// 	//switch can only use int, char, or enum types, so i can't use it with std::string
// 	switch (level[0])
// 	{
// 		case 'D':
// 			(this->*funcs[0])();
// 			//fall-through
// 		case 'I':
// 			(this->*funcs[1])();
// 			//fall-through
// 		case 'W':
// 			(this->*funcs[2])();
// 			//fall-through
// 		case 'E':
// 			(this->*funcs[3])();
// 			break;
// 		default:
// 			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
// 			break;
// 	}
// }