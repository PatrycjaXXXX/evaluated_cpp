/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:53:04 by psmolich          #+#    #+#             */
/*   Updated: 2026/09/26 15:25:40 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: _firstName(""), _lastName(""), _nickname(""),
		_phoneNumber(""), _darkestSecret("")
{
}

Contact::Contact(const std::string & firstName,
				const std::string & lastName,
				const std::string & nickname,
				const std::string & phoneNumber,
				const std::string & darkestSecret)
	: _firstName(firstName), _lastName(lastName), _nickname(nickname),
		_phoneNumber(phoneNumber), _darkestSecret(darkestSecret)
{
}

const std::string &	Contact::getFirstName() const
{
	return (_firstName);
}

const std::string &	Contact::getLastName() const
{
	return (_lastName);
}

const std::string &	Contact::getNickname() const
{
	return (_nickname);
}

const std::string &	Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

const std::string &	Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}