/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:09:25 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 20:01:20 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(Dog const & copy);
		~Dog();

		Dog &	operator=(Dog const &ref);
		void	makeSound() const;
	private:
		Brain	*_brain;
};

#endif
