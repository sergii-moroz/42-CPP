#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook: constructor" << std::endl;
	this->_id = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook: destructor" << std::endl;
}

void	PhoneBook::run(void)
{
	std::string	cmd;

	std::cout << "Phone book is started" << std::endl;
	std::cin >> cmd;
	while (cmd.compare("EXIT"))
	{
		if (cmd.compare("ADD") == 0)
			this->_addContact();
		else if (cmd.compare("SEARCH") == 0)
			this->_search();
		else
			std::cout << "You typed: " << cmd << std::endl;
		std::cin >> cmd;
	}
}

void	PhoneBook::_addContact(void)
{
	std::string	fName;
	std::string	lName;
	std::string	nName;
	std::string	phone;
	std::string secret;

	std::cout << "=== ADD ===" << std::endl;
	std::cout << "You are about to adding a contact " << std::endl;

	std::cout << "First Name: ";
	std::cin >> fName;

	std::cout << "Last Name: ";
	std::cin >> lName;

	std::cout << "Nick Name: ";
	std::cin >> nName;

	std::cout << "Phone Number: ";
	std::cin >> phone;

	std::cout << "Dark Secret: ";
	std::cin >> secret;


	_contacts[_id] = Contact(fName, lName, nName, phone, secret);
	_nextId();
	std::cout << "=== END ADD ===" << std::endl;
}

void	PhoneBook::_search(void)
{
	std::cout << "=== SEARCH ===" << std::endl;
	std::cout << "You search contact " << std::endl;
	_displayAll();
	std::cout << "=== END SEARCH ===" << std::endl;
}

void	PhoneBook::_nextId(void)
{
	this->_id = (this->_id + 1) % 8;
}

void	PhoneBook::_displayAll(void)
{
	std:: string	userInput;

	std::cout << std::setw(10) << "index" << "|"
			<< std::setw(10) << "first name" << "|"
			<< std::setw(10) << "last Name" << "|"
			<< std::setw(10) << "nickname" << std::endl;
	std::cout << "Enter contact id [0-7] to show contact's details" << std::endl;
	std::cout << "Enter any other key to return to previous menu" << std::endl;
	std::cout << "Your choiche: ";
	std::cin >> userInput;
	int	n = userInput.compare("0");
	if (n >= 0 && n <= 9)
	{
		_displayRecord(n);
	}
}

void	PhoneBook::_displayRecord(int id)
{
	std::cout << "first name: " << _contacts[id].getFirstName() << std::endl;
	std::cout << "last name: " << _contacts[id].getLastName() << std::endl;
	std::cout << "nickname: " << _contacts[id].getNickName() << std::endl;
	std::cout << "phone number: " << _contacts[id].getPhoneNumber() << std::endl;
	std::cout << "dark secret: " << _contacts[id].getDarkSecret() << std::endl;
}
