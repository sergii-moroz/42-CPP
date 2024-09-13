/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:21:37 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/12 19:27:59 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

class ICharacter;

class AMateria
{
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & copy);
		AMateria &			operator=(AMateria const & ref);

		std::string const &	getType() const;
		void				setType(std::string const & type);

		virtual AMateria	*clone() = 0;
		virtual void		use(ICharacter & target);

	protected:
		std::string	_type;
};

#endif
