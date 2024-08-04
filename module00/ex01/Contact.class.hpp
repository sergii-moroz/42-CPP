#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;
	public:
		Contact(void);
		Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret);
		int	setFirstName(std::string name);
};

#endif