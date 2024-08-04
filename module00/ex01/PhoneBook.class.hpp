#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.class.hpp"

class	PhoneBook {
	private:
		Contact	_contacts[8];
		int		_id;
		void	_addContact(void);
		void	_search(void);
		void	_displayAll(void);
		void	_displayRecord(int id);
		//std::string	_ask(std::string str);
		void	_nextId(void);

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	run(void);
};

#endif