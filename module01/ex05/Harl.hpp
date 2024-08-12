#ifndef HARL_H
# define HARL_H

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

# include <iostream>
# include <string>

class Harl
{
	private:
		void	debug( void ) const;
		void	info( void ) const;
		void	warning( void ) const;
		void	error( void ) const;
	public:
		void	complain( std::string level ) const;
};

#endif
