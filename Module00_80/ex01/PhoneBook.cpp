/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   PhoneBook.cpp									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/09/25 13:53:27 by psmolich		  #+#	#+#			 */
/*   Updated: 2026/09/26 16:08:41 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: _savedContacts(0), _nextSlot(0)
{
	std::cout << "Phonebook created." << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed." << std::endl;
}

void	PhoneBook::addContact()
{
	std::string	firstName = promptField("First name");
	std::string	lastName = promptField("Last name");
	std::string	nickname = promptField("Nickname");
	std::string	phoneNumber = promptField("Phone number");
	std::string	darkestSecret = promptField("Darkest secret");

	_contacts[_nextSlot] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	_nextSlot = (_nextSlot + 1) % MAX_CONTACTS;
	if (_savedContacts < MAX_CONTACTS)
		_savedContacts++;
	std::cout << "Contact added successfully." << std::endl;
}

std::string	PhoneBook::promptField(const std::string & prompt)
{
	std::string	value;

	while (true)
	{
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, value))
			exit(1);
		if (!value.empty())
			break;
	}
	return (value);
}

void	PhoneBook::searchContact() const
{
	displayContacts();
	if (_savedContacts == 0)
		return ;

	int	index;
	while (true)
	{
		std::cout << "Enter the index of the contact to display: ";

		if (!(std::cin >> index))
		{
			if (std::cin.eof())
				exit(1); // EOF (Ctrl+D)
			std::cin.clear(); // clears the error state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discards invalid input
			std::cout << "Index must be a decimal number\n";
			continue;
		}

		if (index >= 1 && index <= _savedContacts)
			break ;

		std::cout << "Index must be between " << 1 << " and " << _savedContacts << ".\n";
	}
	
	std::cout << "First name:	" << _contacts[index-1].getFirstName() << "\n";
	std::cout << "Last name:	 " << _contacts[index-1].getLastName() << "\n";
	std::cout << "Nickname:	  " << _contacts[index-1].getNickname() << "\n";
	std::cout << "Phone number:  " << _contacts[index-1].getPhoneNumber() << "\n";
	std::cout << "Darkest secret:" << _contacts[index-1].getDarkestSecret() << std::endl;
}

void	PhoneBook::displayContacts() const
{
	std::cout << std::setw(WIDTH) << std::ALIGNMENT << "INDEX" << SEPARATOR
			  << std::setw(WIDTH) << std::ALIGNMENT << "FIRST NAME" << SEPARATOR
			  << std::setw(WIDTH) << std::ALIGNMENT << "LAST NAME" << SEPARATOR
			  << std::setw(WIDTH) << std::ALIGNMENT << "NICKNAME" << std::endl;
	for (int i = 0; i < _savedContacts; i++)
	{
		std::cout << std::setw(WIDTH) << std::ALIGNMENT << i+1 << SEPARATOR
				  << std::setw(WIDTH) << std::ALIGNMENT << formatField(_contacts[i].getFirstName()) << SEPARATOR
				  << std::setw(WIDTH) << std::ALIGNMENT << formatField(_contacts[i].getLastName()) << SEPARATOR
				  << std::setw(WIDTH) << std::ALIGNMENT << formatField(_contacts[i].getNickname()) << std::endl;
	}
}

std::string	PhoneBook::formatField(const std::string & field) const
{
	if (field.length() > WIDTH)
		return (field.substr(0, WIDTH - 1) + ".");
	return (field);
}