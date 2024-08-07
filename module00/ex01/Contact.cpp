#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){}

Contact::Contact(
		std::string first,
		std::string last,
		std::string nick,
		std::string number,
		std::string secret
	) :
		_firstName(first),
		_lastName(last),
		_nickName(nick),
		_phoneNumber(number),
		_darkSecret(secret)
{}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phone)
{
	this->_phoneNumber = phone;
}

void	Contact::setDarkSecret(std::string secret)
{
	this->_darkSecret = secret;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string	Contact::getNickName(void) const
{
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkSecret(void) const
{
	return (this->_darkSecret);
}
