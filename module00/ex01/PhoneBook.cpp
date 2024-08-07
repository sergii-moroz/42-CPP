#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_id = 0;
}

void	PhoneBook::_nextId(void)
{
	_id = (_id + 1) % 8;
}

std::string	PhoneBook::_truncate(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::_usage(void) const
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

void	PhoneBook::_usageDetails(void) const
{
	std::cout << BLACK << "Enter contact's index [ " << MAGENTA << "0 - 7"
		<< BLACK" ] to show contact's details" << RESET << std::endl;
	std::cout << BLACK << "Enter any other key to return to previous menu"
		<< RESET << std::endl;
}

std::string	PhoneBook::_userCmd(void) const
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
			_addContact();
		else if (cmd.compare("SEARCH") == 0)
			_searchRecords();
		else
			std::cout << RED << "Unrecognized command: \"" << cmd
				<< "\"" << RESET << std::endl;
		_usage();
		cmd = _userCmd();
	}
}

std::string	PhoneBook::_readString(std::string msg) const
{
	std::string	str;

	std::cout << BLACK << msg + ": " << RESET;
	std::getline (std::cin, str);
	while (str.empty())
	{
		std::cout << RED << "field couldn't be empty" << RESET << std::endl;
		std::cout << BLACK << msg + ": " << RESET;
		std::getline (std::cin, str);
	}
	return (str);
}

std::string	PhoneBook::_readNumber(std::string msg) const
{
	std::string	str;

	std::cout << BLACK << msg + ": " << RESET;
	std::getline (std::cin, str);
	while (str.empty() || str.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << RED << "field couldn't be empty and should consist only from digits" << RESET << std::endl;
		std::cout << BLACK << msg + ": " << RESET;
		std::getline (std::cin, str);
	}
	return (str);
}

void	PhoneBook::_addContact(void)
{
	std::string	fName;
	std::string	lName;
	std::string	nName;
	std::string	phone;
	std::string secret;

	std::cout << YELLOW << "adding new contact..." << RESET << std::endl;
	fName = _readString("First name");
	lName = _readString("Last name");
	nName = _readString("Nickname");
	phone = _readNumber("Phone number");
	secret = _readString("Dark secret");
	_contacts[_id] = Contact(fName, lName, nName, phone, secret);
	_nextId();
	std::cout << YELLOW << "new contact was successfully added" << RESET << std::endl;
}

void	PhoneBook::_searchRecords(void) const
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

void	PhoneBook::_displayAllRecords(void) const
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

void	PhoneBook::_displayRecord(int id) const
{
	std::cout << BLACK << std::setw(14) << "first name: " << RESET
		<< "\"" + _contacts[id].getFirstName() + "\"" << std::endl;
	std::cout << BLACK << std::setw(14) << "last name: " << RESET
		<< "\"" + _contacts[id].getLastName() + "\"" << std::endl;
	std::cout << BLACK << std::setw(14) << "nickname: " << RESET
		<< "\"" + _contacts[id].getNickName() + "\"" << std::endl;
	std::cout << BLACK << std::setw(14) << "phone number: " << RESET
		<< "\"" + _contacts[id].getPhoneNumber() + "\"" << std::endl;
	std::cout << BLACK << std::setw(14) << "dark secret: " << RESET
		<< "\"" + _contacts[id].getDarkSecret() + "\"" << std::endl << std::endl;
}

std::string	PhoneBook::_dash(int n) const
{
	std::string	str;

	for (int i = 0; i < n; i++)
		str += "-";
	return (str);
}
