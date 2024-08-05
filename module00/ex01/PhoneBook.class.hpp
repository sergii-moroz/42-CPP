#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.class.hpp"

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

class	PhoneBook {
	private:
		Contact	_contacts[8];
		int		_id;

		void	_nextId(void);
		void	_addContact(void);

		void	_searchRecords(void) const;
		void	_displayAllRecords(void) const;
		void	_displayRecord(int id) const;
		void	_usage(void) const;
		void	_usageDetails(void) const;
		std::string	_readString(std::string msg) const;
		std::string	_readNumber(std::string msg) const;
		std::string	_truncate(std::string str) const;
		std::string	_userCmd(void) const;
		std::string	_dash(int n) const;
	public:
		PhoneBook(void);
		void	run(void);
};

#endif
