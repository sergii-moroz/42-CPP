#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void){}

Contact::Contact(
		std::string first,
		std::string last,
		std::string nick,
		std::string number,
		std::string secret
	) :
		firstName(first),
		lastName(last),
		nickName(nick),
		phoneNumber(number),
		darkSecret(secret)
{
	std::cout << "Contact: constructor" << std::endl;
}
