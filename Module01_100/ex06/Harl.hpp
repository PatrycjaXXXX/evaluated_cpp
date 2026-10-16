/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:07:45 by psmolich          #+#    #+#             */
/*   Updated: 2026/10/02 17:09:18 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define NUM_LEVELS 4

# define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define DEBUG_BG "\033[47m"

# define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define INFO_BG "\033[44m"

# define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
# define WARNING_BG "\033[43m"

# define ERROR_MSG "This is unacceptable! I want to speak to the manager now."
# define ERROR_BG "\033[41m"

# define RESET "\033[0m"

class	Harl
{
	public:
		void	complain(std::string level);
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
};

// he told me to do so: https://isocpp.org/wiki/faq/pointers-to-members
typedef void (Harl::*HarlFuncPtrArr[NUM_LEVELS])(void);

#endif