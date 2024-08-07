#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkSecret;
	public:
		Contact(void);
		Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret);
		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickName(std::string nickName);
		void	setPhoneNumber(std::string phone);
		void	setDarkSecret(std::string secret);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkSecret(void) const;
};

#endif
