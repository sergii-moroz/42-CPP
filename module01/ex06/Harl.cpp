#include "Harl.hpp"

void	Harl::complain( std::string level) const
{
	std::string	levels[4] = { "debug", "info", "warning", "error" };
	void	(Harl::*f[4])(void) const = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(levels[i]) == 0)
		{
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "Unknown level: \"" << level << "\"" << std::endl;
}

void	Harl::debug( void ) const
{
	std::cout << CYAN << "DEBUG: "
		<< "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!" << RESET << std::endl;
}

void	Harl::info( void ) const
{
	std::cout << BLACK << "INFO: "
		<< " cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! "
		<< "If you did, I wouldn't be asking for more!" << RESET << std::endl;
}

void	Harl::warning( void ) const
{
	std::cout << YELLOW << "WARNING: "
		<< "I think, I deserve to have some extra bacon for free. "
		<< "I've been coming for years whereas you started working here since last month."
		<< RESET << std::endl;
}

void	Harl::error( void ) const
{
	std::cout << RED << "ERROR: "
	<< "This is unacceptable! I want to speak to the manager now."
	<< RESET << std::endl;
}
