/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:53:09 by psmolich          #+#    #+#             */
/*   Updated: 2026/09/26 15:25:45 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		Contact();
		Contact(const std::string & firstName,
				const std::string & lastName,
				const std::string & nickname,
				const std::string & phoneNumber,
				const std::string & darkestSecret);

		const std::string &	getFirstName() const;
		const std::string &	getLastName() const;
		const std::string &	getNickname() const;
		const std::string &	getPhoneNumber() const;
		const std::string &	getDarkestSecret() const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
} ;

#endif