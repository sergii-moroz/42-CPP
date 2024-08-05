#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	this->_id = 0;
}

std::string	PhoneBook::_truncate(std::string str)
{
	if (str.length() > 8)
		return (str.substr(0, 7) + ".");
	return (str);
}

void	PhoneBook::_usage(void)
{
	std::cout << std::endl;
	std::cout << YELLOW << "Phone Book usage:"<< RESET << std::endl;
	std::cout << MAGENTA << std::setw(6) << "ADD"
		<< BLACK << " : add new contact" << RESET << std::endl;
	std::cout << MAGENTA << std::setw(6) << "SEARCH"
		<< BLACK << " : search for existing contact" << RESET << std::endl;
	std::cout << MAGENTA << std::setw(6) << "EXIT"
		<< BLACK << " : exit the programm" << RESET << std::endl << std::endl;
}

void	PhoneBook::_usageDetails(void)
{
	std::cout << BLACK << "Enter contact's index [ " << MAGENTA << "0 - 7"
		<< BLACK" ] to show contact's details" << RESET << std::endl;
	std::cout << BLACK << "Enter any other key to return to previous menu"
		<< RESET << std::endl;
}

std::string	PhoneBook::_userCmd(void)
{
	std::string	cmd;

	std::cout << MAGENTA;
	std::getline(std::cin, cmd);
	std::cout << RESET << std::endl;
	return (cmd);
}

void	PhoneBook::run(void)
{
	std::string	cmd;

	_usage();
	cmd = _userCmd();

	while (cmd.compare("EXIT"))
	{
		if (cmd.compare("ADD") == 0)
			this->_addContact();
		else if (cmd.compare("SEARCH") == 0)
			this->_searchRecords();
		else
			std::cout << "You typed: " << cmd << std::endl;
		_usage();
		cmd = _userCmd();
	}
}

void	PhoneBook::_addContact(void)
{
	std::string	fName;
	std::string	lName;
	std::string	nName;
	std::string	phone;
	std::string secret;

	std::cout << YELLOW << "adding new contact..." << RESET << std::endl;
	std::cout << BLACK << "First Name: " << RESET;
	std::getline (std::cin, fName);
	std::cout << BLACK << "Last Name: " << RESET;
	std::getline (std::cin, lName);
	std::cout << BLACK << "Nick Name: " << RESET;
	std::getline(std::cin, nName);
	std::cout << BLACK << "Phone Number: " << RESET;
	std::getline(std::cin, phone);
	std::cout << BLACK << "Dark Secret: " << RESET;
	std:getline(std::cin, secret);
	_contacts[_id] = Contact(fName, lName, nName, phone, secret);
	_nextId();
	std::cout << YELLOW << "new contact was successfully added" << RESET << std::endl;
}

void	PhoneBook::_searchRecords(void)
{
	std:: string	userInput;
	int				n;

	_displayAllRecords();
	_usageDetails();
	std::cout << std::endl << YELLOW << "Your choice: " << RESET;
	userInput = _userCmd();
	n = userInput.compare("0");
	while (n >= 0 && n <= 7)
	{
		_displayRecord(n);
		_usageDetails();
		std::cout << std::endl << YELLOW << "Your choice: " << RESET;
		userInput = _userCmd();
		n = userInput.compare("0");
	}
}

void	PhoneBook::_nextId(void)
{
	this->_id = (this->_id + 1) % 8;
}

void	PhoneBook::_displayAllRecords(void)
{
	std::cout << CYAN << std::setw(10) << "index" << BLACK"|"
		<< CYAN << std::setw(10) << "first name" << BLACK"|"
		<< CYAN << std::setw(10) << "last Name" << BLACK"|"
		<< CYAN << std::setw(10) << "nickname" << RESET << std::endl;
	std::cout << BLACK << _dash(10) << "|" << _dash(10) << "|"
		<< _dash(10) << "|" << _dash(10) << RESET << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << MAGENTA << std::setw(10) << i << BLACK"|"
			<< RESET << std::setw(10) << _truncate(_contacts[i].getFirstName()) << BLACK"|"
			<< RESET << std::setw(10) << _truncate(_contacts[i].getLastName()) << BLACK"|"
			<< RESET << std::setw(10) << _truncate(_contacts[i].getNickName()) << RESET << std::endl;

	}
}

void	PhoneBook::_displayRecord(int id)
{
	std::cout << BLACK << std::setw(14) << "first name: " << RESET
		<< _contacts[id].getFirstName() << std::endl;
	std::cout << BLACK << std::setw(14) << "last name: " << RESET
		<< _contacts[id].getLastName() << std::endl;
	std::cout << BLACK << std::setw(14) << "nickname: " << RESET
		<< _contacts[id].getNickName() << std::endl;
	std::cout << BLACK << std::setw(14) << "phone number: " << RESET
		<< _contacts[id].getPhoneNumber() << std::endl;
	std::cout << BLACK << std::setw(14) << "dark secret: " << RESET
		<< _contacts[id].getDarkSecret() << std::endl << std::endl;
}

std::string	PhoneBook::_dash(int n)
{
	std::string	str;

	for (int i = 0; i < n; i++)
		str += "-";
	return (str);
}
