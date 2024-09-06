/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:07:43 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 19:51:15 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(AAnimal const & ref);
		virtual ~AAnimal();

		void			setType(std::string type);
		std::string		getType() const;

		AAnimal &		operator=(AAnimal const & copy);
		virtual void	makeSound() const = 0;

	protected:
		std::string		_type;
};

std::ostream &	operator<<(std::ostream & out, AAnimal const & ref);

#endif
