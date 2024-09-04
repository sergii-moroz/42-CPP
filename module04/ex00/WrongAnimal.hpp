/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:07:43 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/04 09:11:42 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal const & ref);
		~WrongAnimal();

		void		setType( std::string type );
		std::string	getType() const;

		WrongAnimal &	operator=( WrongAnimal const & copy );
		void		makeSound() const;
};

std::ostream &	operator<<(std::ostream out, WrongAnimal const & ref);

#endif
