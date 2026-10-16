/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:53:35 by psmolich          #+#    #+#             */
/*   Updated: 2026/09/26 16:32:14 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream> // cout cin
# include <iomanip> // setw
# include <ios> // right/left/internal
# include <string> // getline
# include <cstdlib> // exit
#include <limits> // for cin buffor ignore

# define MAX_CONTACTS 8
# define SEPARATOR "|"
# define ALIGNMENT right
# define WIDTH 10

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void		addContact();
		void		searchContact() const;

	private:
		Contact		_contacts[MAX_CONTACTS];
		int			_savedContacts;
		int			_nextSlot;

		std::string	promptField(const std::string & prompt);
		void		displayContacts() const;
		std::string	formatField(const std::string & field) const;
} ;

#endif

/*
searchContact() is const because it is an inspector method that does not modify
				the logical state of the object
*/