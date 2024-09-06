/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:07:43 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 18:22:04 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal const & ref);
		virtual ~WrongAnimal();

		void			setType( std::string type );
		std::string		getType() const;

		WrongAnimal &	operator=( WrongAnimal const & copy );
		void			makeSound() const;
	protected:
		std::string	_type;
};

std::ostream &	operator<<(std::ostream & out, WrongAnimal const & ref);

#endif
