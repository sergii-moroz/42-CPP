/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:07:43 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/04 20:12:17 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal( Animal const & ref);
		virtual ~Animal();

		void		setType( std::string type );
		std::string	getType() const;

		Animal &	operator=( Animal const & copy );
		void		makeSound() const;
};

std::ostream &	operator<<(std::ostream out, Animal const & ref);

#endif
