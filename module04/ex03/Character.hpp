/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:30:51 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 21:24:01 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(Character const &);
		Character(std::string const &);
		~Character();
		Character &	operator=(Character const &);
		std::string const &	getName() const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter & target);

	private:
		std::string	_name;
		AMateria	*_inventory[4];
};

#endif
